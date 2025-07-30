#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

class Node {
public:
    int val {};
    std::vector<Node*> neighbors {};
    
    Node() : val{0} {
        neighbors = std::vector<Node*>();
    }
    
    Node(int val) : val{val} {
        neighbors = std::vector<Node*>();
    }
    
    Node(int val, std::vector<Node*>& neighbors) : val{val} {
        this->val = val;
        this->neighbors = neighbors;
    }
};

class Solution {
public:
    static Node* clone_graph_dfs(Node* node, std::map<Node*, Node*>& original_to_copy) {
        if (node == nullptr) {
            return nullptr;
        }

        if (original_to_copy.contains(node)) {
            return original_to_copy[node];
        }
        
        Node* copy = new Node(node->val);
        original_to_copy[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(clone_graph_dfs(neighbor, original_to_copy));
        }

        return copy;
    }

    static Node* cloneGraph(Node* node) {
        std::map<Node*, Node*> original_to_copy {};
        return clone_graph_dfs(node, original_to_copy);
    }

    static void dfs_print(Node* node) {
        std::set<Node*> visited {};
        std::stack<Node*> stack {};
        stack.push(node);

        while (!stack.empty()) {
            Node* curr = stack.top();
            stack.pop();

            std::cout << curr->val << ": [ ";
            for (Node* neighbor : curr->neighbors) {
                std::cout << neighbor->val << ' ';
                if (!visited.contains(neighbor)) {
                    stack.push(neighbor);
                    visited.insert(curr);
                }
            }
            std::cout << "]\n";
        }
    }
};

int main() {
    Node a {1};
    Node b {2};
    Node c {3};

    a.neighbors = {&b};
    b.neighbors = {&a, &c};
    c.neighbors = {&b};

    Node* clone1 = Solution::cloneGraph(&a);
    Solution::dfs_print(clone1);
}
#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	static std::vector<std::vector<int>> levelOrder(TreeNode* root) {
		std::vector<std::vector<int>> node_levels {};
		std::stack<TreeNode*> parents {};
		std::stack<TreeNode*> children {};
		if (root) parents.push(root);
		
		while (!parents.empty()) {
			std::vector<int> node_level {};

			while (!parents.empty()) {
				if (parents.top()->left) children.push(parents.top()->left);
				if (parents.top()->right) children.push(parents.top()->right);
				node_level.push_back(parents.top()->val);
				parents.pop();
			}

			while (!children.empty()) {
				parents.push(children.top());
				children.pop();
			}

			if (!node_level.empty()) node_levels.push_back(node_level);
		}

		return node_levels;
	}
};

int main() {
	TreeNode g {7};
	TreeNode f {6};
	TreeNode e {5};
	TreeNode d {4};
	TreeNode c {3, &f, &g};
	TreeNode b {2, &d, &e};
	TreeNode a {1, &b, &c};

	std::vector<std::vector<int>> node_levels {Solution::levelOrder(&a)};

	std::cout << "[ ";
	for (std::vector vec : node_levels) {
		std::cout << "[ ";
		for (int num : vec) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";
}
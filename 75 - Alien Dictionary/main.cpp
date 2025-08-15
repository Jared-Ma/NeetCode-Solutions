#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    static std::string foreignDictionary(std::vector<std::string>& words) {
        std::unordered_map<char, std::unordered_set<char>> adjacency_map {};

        for (int i = 0; i < static_cast<int>(words.size() - 1); ++i) {
            int min_length = static_cast<int>(std::min(words[i].length(), words[i+1].length()));
            
            if (
                words[i].length() > words[i+1].length() && 
                words[i].substr(0, min_length) == words[i+1].substr(0, min_length)
            ) {
                return "";
            }

            for (int j = 0; j < min_length; ++j) {
                if (words[i][j] != words[i+1][j]) {
                    adjacency_map[words[i][j]].insert(words[i+1][j]);
                    break;
                }
            }
        }

        std::unordered_set<char> unique_chars {};
        for (std::string word : words) {
            for (char c : word) {
                unique_chars.insert(c);
            }
        }

        std::unordered_map<char, int> indegree_map(unique_chars.size());
        for (char node : unique_chars) {
            indegree_map[node] = 0;
        }

        for (const auto& [node, neighbors] : adjacency_map) {
            for (char neighbor : neighbors) {
                indegree_map[neighbor]++;
            }
        }

        std::queue<char> queue {};
        for (const auto& [node, indegree] : indegree_map) {
            if (indegree == 0) {
                queue.push(node);
            }
        }

        std::string result {};
        while (!queue.empty()) {
            char node = queue.front();
            queue.pop();
            result.push_back(node);

            for (char neighbor : adjacency_map[node]) {
                indegree_map[neighbor]--;
                if (indegree_map[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        
        if (result.length() != unique_chars.size()) {
            return "";
        }

        return result;
    }
};

int main() {
    std::vector<std::string> words1 {"z", "o"};
    std::cout << Solution::foreignDictionary(words1) << '\n';
    std::vector<std::string> words2 {"hrn", "hrf", "er", "enn", "rfnn"};
    std::cout << Solution::foreignDictionary(words2) << '\n';
    std::vector<std::string> words3 {"wrtkj", "wrt"};
    std::cout << Solution::foreignDictionary(words3) << '\n';
}

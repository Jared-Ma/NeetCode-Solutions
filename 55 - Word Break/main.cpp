#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
	static bool dfs(std::string s, std::vector<std::string>& wordDict, size_t pos, std::unordered_map<size_t, bool>& memo) {
		if (pos == s.length()) {
			return true;
		}

		if (memo.contains(pos)) {
			return memo[pos];
		}

		for (std::string word : wordDict) {
			if (pos + word.length() <= s.length() && s.substr(pos, word.length()) == word) {
				if (dfs(s, wordDict, pos + word.length(), memo)) {
					memo[pos] = true;
					return true;
				}
			}
		}
		memo[pos] = false;

		return false;
	}

	static bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
		std::unordered_map<size_t, bool> memo {};
		return dfs(s, wordDict, 0, memo);
	}
};

int main() {
	std::string s1 {"neetcode"};
	std::vector<std::string> wordDict1 {"neet", "code"};
	std::cout << std::boolalpha << Solution::wordBreak(s1, wordDict1) << '\n';
	std::string s2 {"applepenapple"};
	std::vector<std::string> wordDict2 {"pen", "apple", "ape"};
	std::cout << std::boolalpha << Solution::wordBreak(s2, wordDict2) << '\n';
	std::string s3 {"catsincars"};
	std::vector<std::string> wordDict3 {"cats", "cat", "sin", "in", "car"};
	std::cout << std::boolalpha << Solution::wordBreak(s3, wordDict3) << '\n';
}
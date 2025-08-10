#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	static int dfs(int i, int j, std::string text1, std::string text2, std::vector<std::vector<int>>& memo) {
		if (i >= text1.size() || j >= text2.size()) {
			return 0;
		}

		if (memo[i][j] != -1) {
			return memo[i][j];
		}
		
		if (text1[i] == text2[j]) {
			memo[i][j] = 1 + dfs(i + 1, j + 1, text1, text2, memo);
		} else {
			memo[i][j] = std::max(dfs(i + 1, j, text1, text2, memo), dfs(i, j + 1, text1, text2, memo));
		}
		return memo[i][j];
	}

	static int longestCommonSubsequence(std::string text1, std::string text2) {
		std::vector<std::vector<int>> memo(text1.size(), std::vector<int>(text2.size(), -1));
		return dfs(0, 0, text1, text2, memo);
	}
};

int main() {
	std::string text1_a {"cat"};
	std::string text1_b {"crabt"};
	std::cout << Solution::longestCommonSubsequence(text1_a, text1_b) << '\n';

	std::string text2_a {"abcd"};
	std::string text2_b {"abcd"};
	std::cout << Solution::longestCommonSubsequence(text2_a, text2_b) << '\n';

	std::string text3_a {"abcd"};
	std::string text3_b {"efgh"};
	std::cout << Solution::longestCommonSubsequence(text3_a, text3_b) << '\n';
}
#include <iostream>
#include <vector>

class Solution {
public:
	static int64_t uniquePaths(int m, int n) {
		int64_t numerator {1};
		int64_t denominator {1};

		// optimize for potential integer overflow
		for (int i = m + n - 2; i > std::max(m-1, n-1); --i) {
			numerator *= i;
		}

		for (int i = 1; i <= std::min(m-1, n-1); ++i) {
			denominator *= i;
		}

		return numerator / denominator;
	}

	static int uniquePathsDFS(int m, int n) {
		std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
		return dfs(0, 0, m, n, memo);
	}

	static int dfs(int i, int j, int m, int n, std::vector<std::vector<int>> memo) {
		if (i == m - 1 && j == n - 1) {
			return 1;
		}
		if (i >= m || j >= n) {
			return 0;
		}
		if (memo[i][j] != -1) {
			return memo[i][j];
		}
		memo[i][j] = dfs(i + 1, j, m, n, memo) + dfs(i, j + 1, m, n, memo);
		return memo[i][j];
	}
};

int main() {
	std::cout << Solution::uniquePaths(3, 6) << '\n';
	std::cout << Solution::uniquePaths(3, 3) << '\n';
	std::cout << Solution::uniquePaths(10, 10) << '\n';
	std::cout << Solution::uniquePathsDFS(3, 6) << '\n';
	std::cout << Solution::uniquePathsDFS(3, 3) << '\n';
	std::cout << Solution::uniquePathsDFS(10, 10) << '\n';
}
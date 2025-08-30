#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
		if (
			i < 0 || i >= static_cast<int>(grid.size()) ||
			j < 0 || j >= static_cast<int>(grid[0].size()) ||
			grid[i][j] == 0
		) {
			return 0;
		}

		grid[i][j] = 0;
		return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
	}

	static int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
		int max = 0;
		for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
			for (int j = 0; j < static_cast<int>(grid[0].size()); ++j) {
				max = std::max(max, dfs(grid, i, j));
			}
		}
		return max;
	}
};

int main() {
	std::vector<std::vector<int>> grid {
		{0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{0, 1, 1, 0, 1},
		{0, 1, 0, 0, 1}
	};

	std::cout << Solution::maxAreaOfIsland(grid) << '\n';
}

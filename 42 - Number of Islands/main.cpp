#include <iostream>
#include <vector>

class Solution {
public:
	static void remove_island(std::vector<std::vector<char>>& grid, int i, int j) {
		if (
			i < 0 || i >= static_cast<int>(grid.size()) || 
			j < 0 || j >= static_cast<int>(grid[0].size()) ||
			grid[i][j] == '0'
		) {
			return;
		}

		grid[i][j] = '0';

		remove_island(grid, i+1, j);
		remove_island(grid, i-1, j);
		remove_island(grid, i, j+1);
		remove_island(grid, i, j-1);
	}

	static int numIslands(std::vector<std::vector<char>>& grid) {
		int count = 0;

		for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
			for (int j = 0; j < static_cast<int>(grid[0].size()); ++j) {
				if (grid[i][j] == '1') {
					remove_island(grid, i, j);
					count++;
				}
			}
		}

		return count;
	}
};

int main() {
	std::vector<std::vector<char>> grid1 = {
		{'0', '1', '1', '1', '0'},
		{'0', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'}
	};
	std::cout << Solution::numIslands(grid1) << '\n';

	std::vector<std::vector<char>> grid2 = {
		{'1', '1', '0', '0', '1'},
		{'1', '1', '0', '0', '1'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};
	std::cout << Solution::numIslands(grid2) << '\n';
}

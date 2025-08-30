#include <algorithm>
#include <limits>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
	static void islandsAndTreasure(std::vector<std::vector<int>>& grid) {
		int num_rows = static_cast<int>(grid.size());
		int num_cols = static_cast<int>(grid[0].size());

		std::queue<std::vector<int>> cell_queue {};
		std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		for (int i = 0; i < num_rows; ++i) {
			for (int j = 0; j < num_cols; ++j) {
				if (grid[i][j] == 0) {
					cell_queue.push(std::vector<int>{i, j});
				}
			}
		}

		while (!cell_queue.empty()) {
			std::vector<int> cell = cell_queue.front();
			cell_queue.pop();
			
			for (int i = 0; i < 4; ++i) {
				int y = cell[0] + directions[i][0];
				int x = cell[1] + directions[i][1];

				if (
					y < 0 || y >= num_rows ||
					x < 0 || x >= num_cols ||
					grid[y][x] != INT_MAX
				) {
					continue;
				}

				grid[y][x] = grid[cell[0]][cell[1]] + 1;
				cell_queue.push(std::vector<int>{y, x});
			}
		}
	}
};

int main() {
	std::vector<std::vector<int>> grid1 {
		{INT_MAX, -1 , 0, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, -1},
		{INT_MAX, -1, INT_MAX, -1},
		{0, -1, INT_MAX, INT_MAX}
	};

	Solution::islandsAndTreasure(grid1);

	for (int i = 0; i < static_cast<int>(grid1.size()); ++i) {
		std::cout << "[ ";
		for (int j = 0; j < static_cast<int>(grid1[0].size()); ++j) {
			std::cout << grid1[i][j] << ' ';
		}
		std::cout << "]\n";
	}
	std::cout << '\n';

	std::vector<std::vector<int>> grid2 {
		{0, -1},
		{INT_MAX, INT_MAX}
	};

	Solution::islandsAndTreasure(grid2);

	for (int i = 0; i < static_cast<int>(grid2.size()); ++i) {
		std::cout << "[ ";
		for (int j = 0; j < static_cast<int>(grid2[0].size()); ++j) {
			std::cout << grid2[i][j] << ' ';
		}
		std::cout << "]\n";
	}
}
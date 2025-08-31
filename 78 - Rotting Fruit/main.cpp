#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
	static int orangesRotting(std::vector<std::vector<int>>& grid) {
		int m = static_cast<int>(grid.size());
		int n = static_cast<int>(grid[0].size());
		
		std::queue<std::pair<int, int>> queue {};
		int num_fresh = 0;
		int minute = 0;

		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				if (grid[y][x] == 1) {
					++num_fresh;
				}
				if (grid[y][x] == 2) {
					queue.push(std::pair<int, int>{y, x});
				}
			}
		}

		std::vector<std::pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		while (num_fresh > 0 && !queue.empty()) {
			int length = static_cast<int>(queue.size());

			for (int i = 0; i < length; ++i) {
				int y = queue.front().first;
				int x = queue.front().second;
				queue.pop();

				for (std::pair<int, int> direction : directions) {
					int new_y = y + direction.first;
					int new_x = x + direction.second;
					if (
						new_y >= 0 && new_y < m &&
						new_x >= 0 && new_x < n &&
						grid[new_y][new_x] == 1
					) {
						grid[new_y][new_x] = 2;
						num_fresh--;
						queue.push(std::pair<int, int>{new_y, new_x});
					}
				}
			}

			minute++;
		}

		return num_fresh == 0 ? minute : -1;
	}
};

int main() {
	std::vector<std::vector<int>> grid1 {
		{1, 1, 0},
		{0, 1, 1},
		{0, 1, 2}
	};

	std::cout << Solution::orangesRotting(grid1) << '\n';

	std::vector<std::vector<int>> grid2 {
		{1, 0, 1},
		{0, 2, 0},
		{1, 0, 1}
	};

	std::cout << Solution::orangesRotting(grid2) << '\n';
}
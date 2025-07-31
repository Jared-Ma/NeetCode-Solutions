#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
	static void dfs(
		std::vector<std::vector<int>>& heights, 
		std::vector<std::vector<bool>>& ocean, 
		int row, 
		int col
	) {
		int num_rows = static_cast<int>(heights.size());
		int num_cols = static_cast<int>(heights[0].size());

		ocean[row][col] = true;

		std::vector<std::pair<int, int>> directions = {
			{1, 0}, {-1, 0}, 
			{0, 1}, {0, -1}
		};

		for (const auto& [dr, dc] : directions) {
			if (
				row + dr >= 0 && row + dr < num_rows && 
				col + dc >= 0 && col + dc < num_cols && 
				!ocean[row + dr][col + dc] && 
				heights[row][col] <= heights[row + dr][col + dc] 
			) {
				dfs(heights, ocean, row + dr, col + dc);
			}
		}
	}

	static std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
		int num_rows = static_cast<int>(heights.size());
		int num_cols = static_cast<int>(heights[0].size());

		std::vector<std::vector<bool>> pacific(num_rows, std::vector<bool>(num_cols));
		std::vector<std::vector<bool>> atlantic(num_rows, std::vector<bool>(num_cols));
		
		for (int r = 0; r < num_rows; ++r) {
			dfs(heights, pacific, r, 0);
			dfs(heights, atlantic, r, num_cols - 1);
		}

		for (int c = 0; c < num_cols; ++c) {
			dfs(heights, pacific, 0, c);
			dfs(heights, atlantic, num_rows - 1, c);
		}

		std::vector<std::vector<int>> positions = {};
		for (int r = 0; r < num_rows; ++r) {
			for (int c = 0; c < num_cols; ++c) {
				if (pacific[r][c] && atlantic[r][c]) {
					positions.push_back(std::vector<int>{r, c});
				}
			}
		}

		return positions;
	}
};

int main() {
	std::vector<std::vector<int>> heights1 {
		{4, 2, 7, 3, 4},
		{7, 4, 6, 4, 7},
		{6, 3, 5, 3, 6}
	};

	std::vector<std::vector<int>> positions {Solution::pacificAtlantic(heights1)};

	std::cout << '[';
	for (std::vector<int> position : positions) {
		std::cout << '(' << position[0] << ", " << position[1] << ") ";
	}
	std::cout << "]\n";
}
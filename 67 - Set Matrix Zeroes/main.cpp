#include <iostream>
#include <vector>

class Solution {
public:
	static void setZeroes(std::vector<std::vector<int>>& matrix) {
		int m = static_cast<int>(matrix.size());
		int n = static_cast<int>(matrix[0].size());
		
		bool left_col = false;
		bool top_row = false;
		
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 0) {
				left_col = true;
				break;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (matrix[0][i] == 0) {
				top_row = true;
				break;
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m; ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < n; ++j) {
					matrix[i][j] = 0;
				}
			}
		}

		for (int j = 1; j < n; ++j) {
			if (matrix[0][j] == 0) {
				for (int i = 1; i < m; ++i) {
					matrix[i][j] = 0;
				}
			}
		}

		if (left_col) {
			for (int i = 0; i < m; ++i) {
				matrix[i][0] = 0;
			}
		}

		if (top_row) {
			for (int i = 0; i < n; ++i) {
				matrix[0][i] = 0;
			}
		}

		return;
	}
};

int main() {
	std::vector<std::vector<int>> matrix1 {
		{0, 1},
		{1, 0}
	};

	Solution::setZeroes(matrix1);

	for (std::vector<int> row : matrix1) {
		std::cout << "[ ";
		for (int value : row) {
			std::cout << value << ' ';
		}
		std::cout << "]\n";
	}

	std::vector<std::vector<int>> matrix2 {
		{1, 2, 3},
		{4, 0, 6},
		{7, 8, 9}
	};

	Solution::setZeroes(matrix2);

	for (std::vector<int> row : matrix2) {
		std::cout << "[ ";
		for (int value : row) {
			std::cout << value << ' ';
		}
		std::cout << "]\n";
	}
}
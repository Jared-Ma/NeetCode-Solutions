#include <iostream>
#include <vector>

class Solution {
public:
	static void rotate(std::vector<std::vector<int>>& matrix) {
		int n = static_cast<int>(matrix.size());

		// flip along horizontal axis
		for (int i = 0; i < n/2; ++i) {
			for (int j = 0; j < n; ++j) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-i-1][j];
				matrix[n-i-1][j] = tmp;
			}
		}

		// tranpose
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}

		return;
	}
};

int main() {
	std::vector<std::vector<int>> matrix1 {
		{1, 2},
		{3, 4}
	};

	Solution::rotate(matrix1);

	for (std::vector<int> row : matrix1) {
		std::cout << "[ ";
		for (int value : row) {
			std::cout << value << ' ';
		}
		std::cout << "]\n";
	}

	std::vector<std::vector<int>> matrix2 {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	Solution::rotate(matrix2);

	for (std::vector<int> row : matrix2) {
		std::cout << "[ ";
		for (int value : row) {
			std::cout << value << ' ';
		}
		std::cout << "]\n";
	}

	std::vector<std::vector<int>> matrix3 {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	Solution::rotate(matrix3);

	for (std::vector<int> row : matrix3) {
		std::cout << "[ ";
		for (int value : row) {
			std::cout << value << ' ';
		}
		std::cout << "]\n";
	}
}
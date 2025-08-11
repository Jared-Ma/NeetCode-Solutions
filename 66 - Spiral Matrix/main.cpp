#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		int m = static_cast<int>(matrix.size());
		int n = static_cast<int>(matrix[0].size());

		int top = 0;
		int bottom = m - 1;
		int left = 0;
		int right = n - 1;

		std::vector<int> spiral {};

		while (left <= right && top <= bottom) {
			// top row
			for (int i = left; i <= right; ++i) {
				spiral.push_back(matrix[top][i]);
			}
			++top;

			// right column
			for (int i = top; i <= bottom; ++i) {
				spiral.push_back(matrix[i][right]);
			}
			--right;

			if (!(left <= right && top <= bottom)) {
				break;
			}

			// bottom row
			for (int i = right; i >= left; --i) {
				spiral.push_back(matrix[bottom][i]);
			}
			--bottom;

			// left column
			for (int i = bottom; i >= top; --i) {
				spiral.push_back(matrix[i][left]);
			}
			++left;
		}

		return spiral;
	}
};

int main() {
	std::vector<std::vector<int>> matrix1 {
		{1, 2},
		{3, 4}
	};

	std::vector<int> spiral1 = Solution::spiralOrder(matrix1);

	std::cout << "[ ";
	for (int value : spiral1) {
		std::cout << value << ' ';
	}
	std::cout << "]\n";

	std::vector<std::vector<int>> matrix2 {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	std::vector<int> spiral2 = Solution::spiralOrder(matrix2);

	std::cout << "[ ";
	for (int value : spiral2) {
		std::cout << value << ' ';
	}
	std::cout << "]\n";

	std::vector<std::vector<int>> matrix3 {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	std::vector<int> spiral3 = Solution::spiralOrder(matrix3);

	std::cout << "[ ";
	for (int value : spiral3) {
		std::cout << value << ' ';
	}
	std::cout << "]\n";
}

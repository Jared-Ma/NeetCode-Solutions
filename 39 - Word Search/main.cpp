#include <iostream>
#include <vector>

class Solution {
public:
	static bool search(
		std::vector<std::vector<char>>& board, 
		std::string word, 
		int row,
		int col,
		int index,
		std::vector<std::vector<bool>>& visited
	) {
		if (index == word.length()) {
			return true;
		}

		int num_rows = static_cast<int>(board.size());
		int num_cols = static_cast<int>(board[0].size());

		if (
			row < 0 || row >= num_rows || col < 0 || col >= num_cols ||
			board[row][col] != word[index] || visited[row][col]
		) {
			return false;
		}

		visited[row][col] = true;
		bool result = (
			search(board, word, row + 1, col, index + 1, visited) || 
			search(board, word, row - 1, col, index + 1, visited) ||
			search(board, word, row, col + 1, index + 1, visited) || 
			search(board, word, row, col - 1, index + 1, visited) 
		);
		visited[row][col] = false;

		return result;
	}

	static bool exist(std::vector<std::vector<char>>& board, std::string word) {
		int num_rows = static_cast<int>(board.size());
		int num_cols = static_cast<int>(board[0].size());
		std::vector<std::vector<bool>> visited(num_rows, std::vector<bool>(num_cols));

		for (int row = 0; row < num_rows; ++row) {
			for (int col = 0; col < num_cols; ++col) {
				if (search(board, word, row, col, 0, visited)) {
					return true;
				}
			}
		}

		return false;
	}
};

int main() {
	std::vector<std::vector<char>> board1 = {
		{'A', 'B', 'C', 'D'},
		{'S', 'A', 'A', 'T'},
		{'A', 'C', 'A', 'E'}
	};
	std::string word1 = "CAT";

	std::cout << std::boolalpha << Solution::exist(board1, word1) << '\n';

	std::vector<std::vector<char>> board2 = {
		{'A', 'B', 'C', 'D'},
		{'S', 'A', 'A', 'T'},
		{'A', 'C', 'A', 'E'}
	};
	std::string word2 = "BAT";

	std::cout << std::boolalpha << Solution::exist(board2, word2) << '\n';
}
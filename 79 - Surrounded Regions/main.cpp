#include <iostream>
#include <vector>

class Solution {
public:
	static void dfs(std::vector<std::vector<char>>& board, int y, int x) {
		if (
			y < 0 || y >= static_cast<int>(board.size()) ||
			x < 0 || x >= static_cast<int>(board[0].size()) ||
			board[y][x] == 'X' ||
			board[y][x] == 'Y'
		) {
			return;
		}

		board[y][x] = 'Y';
		dfs(board, y+1, x);
		dfs(board, y-1, x);
		dfs(board, y, x+1);
		dfs(board, y, x-1);

		return;
	}

	static void solve(std::vector<std::vector<char>>& board) {
		int m = static_cast<int>(board.size());
		int n = static_cast<int>(board[0].size());
		
		for (int y = 0; y < m; ++y) {
			if (board[y][0] == 'O') {
				dfs(board, y, 0);
			}
			if (board[y][n-1] == 'O') {
				dfs(board, y, n-1);
			}
		}

		for (int x = 0; x < n; ++x) {
			if (board[0][x] == 'O') {
				dfs(board, 0, x);
			}
			if (board[m-1][x] == 'O') {
				dfs(board, m-1, x);
			}
		}

		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				if (board[y][x] == 'O') {
					board[y][x] = 'X';
				} else if (board[y][x] == 'Y') {
					board[y][x] = 'O';
				}
			}
		}
	}
};

int main() {
	std::vector<std::vector<char>> board1 {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'X', 'O'}
	};

	Solution::solve(board1);

	for (std::vector<char> row : board1) {
		std::cout << "[ ";
		for (char c : row) {
			std::cout << c << ' ';
		}
		std::cout << "]\n";
	}

	std::vector<std::vector<char>> board2 {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'O'}
	};

	Solution::solve(board2);

	for (std::vector<char> row : board2) {
		std::cout << "[ ";
		for (char c : row) {
			std::cout << c << ' ';
		}
		std::cout << "]\n";
	}

	std::vector<std::vector<char>> board3 {
		{'O', 'X', 'X', 'O', 'X'},
		{'X', 'O', 'O', 'X', 'O'},
		{'X', 'O', 'X', 'O', 'X'},
		{'O', 'X', 'O', 'O', 'O'},
		{'X', 'X', 'O', 'X', 'O'}
	};

	Solution::solve(board3);

	for (std::vector<char> row : board3) {
		std::cout << "[ ";
		for (char c : row) {
			std::cout << c << ' ';
		}
		std::cout << "]\n";
	}
}
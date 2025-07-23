#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<int> countBits(int n) {
		std::vector<int> bits(static_cast<size_t>(n + 1));
		int offset = 1;

		for (int i = 1; i <= n; i++) {
			offset = (offset * 2 == i) ? i : offset;
			bits.data()[i] = 1 + bits.data()[i - offset];
		}

		return bits;
	}
};

int main() {
	int n1 = 4;
	std::vector<int> bits1 {Solution::countBits(n1)};

	std::cout << "[ ";
	for (int count : bits1) {
		std::cout << count << ' ';
	}
	std::cout << "]\n";

	int n2 = 10;
	std::vector<int> bits2 {Solution::countBits(n2)};

	std::cout << "[ ";
	for (int count : bits2) {
		std::cout << count << ' ';
	}
	std::cout << "]\n";
}
#include <iostream>
#include <vector>

class Solution {
public:
	static int getSum(int a, int b) {
		bool carry_bit = 0;
		int result = 0;

		for (int i = 0; i < 32; ++i) {
			bool a_bit = a & (1 << i);
			bool b_bit = b & (1 << i);
			result |= (a_bit ^ b_bit ^ carry_bit) << i;
			carry_bit = (a_bit & b_bit) | (a_bit & carry_bit) | (b_bit & carry_bit);
		}

		return result;
	}
};

int main() {
	std::cout << Solution::getSum(1, 1) << '\n';
	std::cout << Solution::getSum(4, 7) << '\n';
	std::cout << Solution::getSum(4, -2) << '\n';
	std::cout << Solution::getSum(-4, 2) << '\n';
}

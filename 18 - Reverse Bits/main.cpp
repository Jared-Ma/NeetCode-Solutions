#include <iostream>

class Solution {
public:
	static uint32_t reverseBits(uint32_t n) {
		uint32_t r {0};
		for (int i = 0; i < 32; ++i) {
			r += ((n >> i) & 1) << (31 - i);
		}
		return r;
	}
};

int main() {
	uint32_t n1 {21};
	std::cout << Solution::reverseBits(n1) << '\n';
}
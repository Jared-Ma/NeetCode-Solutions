#include <iostream>

class Solution {
public:
	static int hammingWeight(uint32_t n) {
		int count = 0;
		for (int i = 0; i < 32; ++i) {
			count += 1 & (n >> i);
		}
		return count;
	} 
};

int main() {
	uint32_t n1 = 23;
	std::cout << Solution::hammingWeight(n1) << '\n';
	uint32_t n2 = 123456789;
	std::cout << Solution::hammingWeight(n2) << '\n';
}
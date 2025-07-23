#include <iostream>
#include <vector>

class Solution {
public:
	static int climbStairs(int n) {
		std::vector<int> prev {1, 2};

		for (int i = 2; i < n; ++i) {
			prev.push_back(prev.data()[i - 1] + prev.data()[i - 2]);
		}

		return prev.data()[n - 1];
	}
};

int main() {
	std::cout << Solution::climbStairs(2) << '\n';
	std::cout << Solution::climbStairs(3) << '\n';
	std::cout << Solution::climbStairs(4) << '\n';
	std::cout << Solution::climbStairs(5) << '\n';
}
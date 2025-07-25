#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static int maxArea(std::vector<int>& heights) {
		int i = 0;
		int j = static_cast<int>(heights.size() - 1);
		int max_area = std::min(heights.data()[i], heights.data()[j]) * (j - i);
		
		while (i < j) {
			if (heights.data()[i] < heights.data()[j]) {
				++i;
			} else {
				--j;
			}
			max_area = std::max(max_area, std::min(heights.data()[i], heights.data()[j]) * (j - i));
		}

		return max_area;
	}
};

int main() {
	std::vector<int> heights1 {1, 7, 2, 5, 4, 7, 3, 6};
	std::cout << Solution::maxArea(heights1) << '\n';

	std::vector<int> heights2 {2, 2, 2};
	std::cout << Solution::maxArea(heights2) << '\n';
}
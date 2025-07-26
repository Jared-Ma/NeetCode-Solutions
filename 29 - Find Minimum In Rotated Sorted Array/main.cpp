#include <iostream>
#include <vector>

class Solution {
public:
	static int findMin(std::vector<int>& nums) {
		int start = 0;
		int end = static_cast<int>(nums.size() - 1);

		while (start < end) {
			int mid = (start + end) / 2;

			if (nums.data()[mid] < nums.data()[end]) {
				end = mid;
			} else {
				start = mid + 1;
			}
		}

		return nums.data()[start];
	}
};

int main() {
	std::vector<int> nums1 {3, 4, 5, 6, 1, 2};
	std::cout << Solution::findMin(nums1) << '\n';

	std::vector<int> nums2 {4, 5, 0, 1, 2, 3};
	std::cout << Solution::findMin(nums2) << '\n';

	std::vector<int> nums3 {4, 5, 6, 7};
	std::cout << Solution::findMin(nums3) << '\n';
}
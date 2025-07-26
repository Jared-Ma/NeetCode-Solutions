#include <iostream>
#include <vector>

class Solution {
public:
	static int findMin(std::vector<int>& nums, int target) {
		int start = 0;
		int end = static_cast<int>(nums.size() - 1);

		while (start <= end) {
			int mid = (start + end) / 2;

			if (nums.data()[mid] == target) {
				return mid;
			}

			if (nums.data()[mid] < nums.data()[end]) {
				if (nums.data()[mid] <= target && target <= nums.data()[end]) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			} else {
				if (nums.data()[start] <= target && target <= nums.data()[mid]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			}
		}

		return -1;
	}
};

int main() {
	std::vector<int> nums1 {3, 4, 5, 6, 1, 2};
	std::cout << Solution::findMin(nums1, 1) << '\n';

	std::vector<int> nums2 {4, 5, 0, 1, 2, 3};
	std::cout << Solution::findMin(nums2, 1) << '\n';

	std::vector<int> nums3 {4, 5, 6, 7};
	std::cout << Solution::findMin(nums3, 0) << '\n';

	std::vector<int> nums4 {1, 3};
	std::cout << Solution::findMin(nums4, 3) << '\n';
}
#include <iostream>
#include <vector>

class Solution {
public:
	static bool canJump(std::vector<int>& nums) {
		if (nums.size() <= 1) {
			return true;
		}

		int jump_length = 1;
		for (int i = static_cast<int>(nums.size() - 2); i >= 1; --i) {
			if (nums[i] >= jump_length) {
				jump_length = 1;
			} else {
				++jump_length;
			}
		}

		return nums[0] >= jump_length;
	}
};

int main() {
	std::vector<int> nums1 {1, 2, 0, 1, 0};
	std::cout << std::boolalpha << Solution::canJump(nums1) << '\n';
	std::vector<int> nums2 {1, 2, 1, 0, 1};
	std::cout << std::boolalpha << Solution::canJump(nums2) << '\n';
}
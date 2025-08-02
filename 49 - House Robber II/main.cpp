#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static int rob(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		return std::max(
			dp_helper(std::vector<int>(nums.begin(), nums.end() - 1)), 
			dp_helper(std::vector<int>(nums.begin() + 1, nums.end()))
		);
	}

	static int dp_helper(const std::vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		std::vector<int> dp(nums.size());

		dp[0] = nums[0];
		dp[1] = std::max(nums[0], nums[1]);

		for (int i = 2; i < static_cast<int>(nums.size()); ++i) {
			dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
		}

		return dp.back();
	}
};

int main() {
	std::vector<int> nums1 {3, 4, 3};
	std::cout << Solution::rob(nums1) << '\n';
	std::vector<int> nums2 {2, 9, 8, 3, 6};
	std::cout << Solution::rob(nums2) << '\n';
}

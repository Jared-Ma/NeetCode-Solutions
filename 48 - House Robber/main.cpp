#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static int rob(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		std::vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = std::max(nums[0], nums[1]);

		for (int i = 2; i < nums.size(); i++) {
			dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
		}

		return dp[nums.size() - 1];
	}
};

int main() {
	std::vector<int> nums1 {1, 1, 3, 3};
	std::cout << Solution::rob(nums1) << '\n';
	std::vector<int> nums2 {2, 9, 8, 3, 6};
	std::cout << Solution::rob(nums2) << '\n';
}
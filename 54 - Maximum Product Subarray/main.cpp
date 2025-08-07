#include <iostream>
#include <vector>

class Solution {
public:
	static int maxProduct(std::vector<int>& nums) {
		// holds the maximum product seen so far
		int result = nums[0];

		// the ith entry holds the minimum product of subarrays within (0, i)
		std::vector<int> min_prods(nums.size());
		min_prods[0] = nums[0];
		
		// the ith entry holds the maximum product of subarrays within (0, i)
		std::vector<int> max_prods(nums.size());
		max_prods[0] = nums[0];

		for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
			max_prods[i] = std::max(nums[i], std::max(max_prods[i-1] * nums[i], min_prods[i-1] * nums[i]));
			min_prods[i] = std::min(nums[i], std::min(min_prods[i-1] * nums[i], max_prods[i-1] * nums[i]));
			result = std::max(result, max_prods[i]);
		}

		return result;
	}
};

int main() {
	std::vector<int> nums1 {1, 2, -3, 4};
	std::cout << Solution::maxProduct(nums1) << '\n';
	std::vector<int> nums2 {-2, -1};
	std::cout << Solution::maxProduct(nums2) << '\n';
}
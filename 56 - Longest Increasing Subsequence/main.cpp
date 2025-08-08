#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static int lengthOfLIS(std::vector<int>& nums) {
		// ith entry holds length of longest strictly increasing subsequence from (0, i)
		std::vector<int> max_lengths(nums.size());

		// loop maintains this invariant for each entry of max_lengths
		for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
			int max_length = 0;
			// find max within previous entries that are strictly less than the current value
			for (int j = i - 1; j >= 0; --j) {
				if (nums[i] > nums[j]) {
					max_length = std::max(max_length, max_lengths[j]);
				}
			}
			max_lengths[i] = max_length + 1;
		}

		return *std::max_element(max_lengths.begin(), max_lengths.end());
	}
};

int main() {
	std::vector<int> nums1 {9, 1, 4, 2, 3, 3, 7};
	std::cout << Solution::lengthOfLIS(nums1) << '\n';
	std::vector<int> nums2 {0, 3, 1, 3, 2, 3};
	std::cout << Solution::lengthOfLIS(nums2) << '\n';
	std::vector<int> nums3 {1, 3, 6, 7, 9, 4, 10, 5, 6};
	std::cout << Solution::lengthOfLIS(nums3) << '\n';
}
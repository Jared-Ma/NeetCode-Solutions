#include <iostream>
#include <vector>

class Solution {
public:
	static int maxSubArray(std::vector<int>& nums) {
        int max = nums[0];
        int sum = 0;

        for (int num : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += num;
            max = std::max(max, sum);
        }

        return max;
    }
};

int main() {
	std::vector<int> nums1 {2, -3, 4, -2, 2, 1, -1, 4};
	std::cout << Solution::maxSubArray(nums1) << '\n';
	std::vector<int> nums2 {-1};
	std::cout << Solution::maxSubArray(nums2) << '\n';
    std::vector<int> nums3 {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << Solution::maxSubArray(nums3) << '\n';
}
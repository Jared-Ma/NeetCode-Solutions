#include <iostream>
#include <vector>

class Solution {
public:
	static int missingNumber(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return n*(n+1)/2 - sum;
	}
};

int main() {
    std::vector<int> nums1 {1, 2, 3};
    std::cout << Solution::missingNumber(nums1) << '\n';

    std::vector<int> nums2 {0, 2};
    std::cout << Solution::missingNumber(nums2) << '\n';
}
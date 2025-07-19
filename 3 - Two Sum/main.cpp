#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> diff = {};

        for (int i = 0; i < nums.size(); ++i) {
            diff[target - nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (diff.count(nums[i]) && i != diff[nums[i]]) {
                return {i, diff[nums[i]]};
            }
        }

        return {};
    }
};

int main() {
    std::vector<int> nums_1 {3, 4, 5, 6};
    int target_1 = 7;

    std::vector<int> solution_1 = Solution::twoSum(nums_1, target_1);
    std::cout << "[ " << solution_1[0] << ' ' << solution_1[1] << " ]\n";

    std::vector<int> nums_2 {4, 5, 6};
    int target_2 = 10;

    std::vector<int> solution_2 = Solution::twoSum(nums_2, target_2);
    std::cout << "[ " << solution_2[0] << ' ' << solution_2[1] << " ]\n";
}
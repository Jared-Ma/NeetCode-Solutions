#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    static bool hasDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> set {};         
        for (int num : nums) {
            if (set.count(num) > 0) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};

int main() {
    std::vector<int> case_1 {1, 2, 3, 4};
    std::cout << std::boolalpha << Solution::hasDuplicate(case_1) << '\n';

    std::vector<int> case_2 {1, 2, 3, 3};
    std::cout << std::boolalpha << Solution::hasDuplicate(case_2) << '\n';
}
#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<int> productExceptSelf(std::vector<int>& nums) {
		int n = static_cast<int>(nums.size());

		std::vector<int> prefix_products {1};
		std::vector<int> suffix_products {1};
		for (int i = 0; i < n - 1; ++i) {
			prefix_products.push_back(prefix_products.data()[i] * nums.data()[i]);
			suffix_products.push_back(suffix_products.data()[i] * nums.data()[n-1-i]);
		}

		std::vector<int> res {};
		for (int i = 0; i < n; ++i) {
			res.push_back(prefix_products.data()[i] * suffix_products.data()[n-1-i]);
		}

		return res;
	}
};

int main() {
	std::vector<int> nums1 = {1, 2, 4, 6};
	std::vector<int> res1 = Solution::productExceptSelf(nums1);

	std::cout << "[ ";
	for (int num : res1) {
		std::cout << num << ' ';
	}
	std::cout << "]\n";

	std::vector<int> nums2 = {-1, 0, 1, 2, 3};
	std::vector<int> res2 = Solution::productExceptSelf(nums2);

	std::cout << "[ ";
	for (int num : res2) {
		std::cout << num << ' ';
	}
	std::cout << "]\n";
}
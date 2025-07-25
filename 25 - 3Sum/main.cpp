#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());

		std::vector<std::vector<int>> triplets {};
		int n = static_cast<int>(nums.size());

		for (int i = 0; i < n; ++i) {
			if (nums.data()[i] > 0) {
				break;
			}
			if (i > 0 && nums.data()[i] == nums.data()[i - 1]) {
				continue;
			}

			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				if (nums.data()[j] + nums.data()[k] < -nums.data()[i]) {
					++j;
				} else if (nums.data()[j] + nums.data()[k] > -nums.data()[i]) {
					--k;
				} else {
					triplets.push_back(std::vector{nums.data()[i], nums.data()[j], nums.data()[k]});
					++j;
					--k;
					while (j < k && nums.data()[j] == nums.data()[j - 1]) {
						++j;
					}
				}
			}
		}

		return triplets;
	}
};

int main() {
	std::vector<int> nums1 {-1, 0, 1, 2, -1, -4};
	std::vector<std::vector<int>> triplets1 {Solution::threeSum(nums1)};

	std::cout << "[ ";
	for (std::vector<int> triplet : triplets1) {
		std::cout << "[ ";
		for (int num : triplet) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	std::vector<int> nums2 {0, 1, 1};
	std::vector<std::vector<int>> triplets2 {Solution::threeSum(nums2)};

	std::cout << "[ ";
	for (std::vector<int> triplet : triplets2) {
		std::cout << "[ ";
		for (int num : triplet) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	std::vector<int> nums3 {0, 0, 0};
	std::vector<std::vector<int>> triplets3 {Solution::threeSum(nums3)};

	std::cout << "[ ";
	for (std::vector<int> triplet : triplets3) {
		std::cout << "[ ";
		for (int num : triplet) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";
}
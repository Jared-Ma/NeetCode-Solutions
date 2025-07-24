#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
public:
	static std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> num_counts {};

		for (int num : nums) {
			num_counts[num]++;
		}

		std::vector<std::vector<int>> buckets(nums.size() + 1);

		for (const auto& [num, count] : num_counts) {
			buckets.data()[count].push_back(num);
		}

		std::vector<int> k_most_frequent {};
		for (int i = static_cast<int>(buckets.size() - 1); i > 0; --i) {
			for (int num : buckets.data()[i]) {
				k_most_frequent.push_back(num);
				if (k_most_frequent.size() == k) {
					return k_most_frequent;
				}
			}
		}
		
		return k_most_frequent;
	}
};

int main() {
	std::vector<int> nums1 {1, 2, 2, 3, 3, 3};
	std::vector<int> res1 = Solution::topKFrequent(nums1, 2);

	std::cout << "[ ";
	for (int num : res1) {
		std::cout << num << ' ';
	}
	std::cout << "]\n";

	std::vector<int> nums2 {7, 7};
	std::vector<int> res2 = Solution::topKFrequent(nums2, 1);
	
	std::cout << "[ ";
	for (int num : res2) {
		std::cout << num << ' ';
	}
	std::cout << "]\n";
}

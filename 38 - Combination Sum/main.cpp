#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
	static std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());

		std::vector<std::vector<int>> combinations {};
		std::vector<int> curr_combination {};

		int index = 0;
		int n = static_cast<int>(nums.size());
		int curr_target = target;
		
		std::unordered_map<int, int> num_indexes {};
		for (int i = 0; i < n; ++i) {
			num_indexes[nums.data()[i]] = i;
		}

		do {
			curr_combination.push_back(nums.data()[index]);
			curr_target -= curr_combination.back();

			if (curr_target < 0) {
				curr_target += curr_combination.back();
				curr_combination.pop_back();
				index++;
			} else if (curr_target == 0) {
				combinations.push_back(curr_combination);
				curr_target += curr_combination.back();
				curr_combination.pop_back();
				index++;
			}

			while (!curr_combination.empty() && index >= n) {
				index = num_indexes[curr_combination.back()] + 1;
				curr_target += curr_combination.back();
				curr_combination.pop_back();
			}
		} while (!curr_combination.empty() || index < n);

		return combinations;
	}

	static void dfs(std::vector<int> curr_combo, int sum, int i, std::vector<int>& nums, int target, std::vector<std::vector<int>>& combos) {
		if (sum == target) {
			combos.push_back(curr_combo);
			return;
		}

		for (int j = i; j < static_cast<int>(nums.size()); j++) {
			if (sum + nums.data()[j] > target) {
				return;
			}
			curr_combo.push_back(nums.data()[j]);
			dfs(curr_combo, sum + nums.data()[j], j, nums, target, combos);
			curr_combo.pop_back();
		}
	}

	static std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> combos {};
		dfs({}, 0, 0, nums, target, combos);
		return combos;
	}
};

int main() {
	std::vector<int> nums1 {2, 5, 6, 9};
	std::vector<std::vector<int>> combinations1 {Solution::combinationSum(nums1, 9)};

	std::cout << "[ ";
	for (std::vector<int> combination : combinations1) {
		std::cout << "[ ";
		for (int num : combination) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	std::vector<int> nums2 {3, 4, 5};
	std::vector<std::vector<int>> combinations2 {Solution::combinationSum(nums2, 16)};

	std::cout << "[ ";
	for (std::vector<int> combination : combinations2) {
		std::cout << "[ ";
		for (int num : combination) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	std::vector<int> nums3 {3};
	std::vector<std::vector<int>> combinations3 {Solution::combinationSum(nums3, 5)};

	std::cout << "[ ";
	for (std::vector<int> combination : combinations3) {
		std::cout << "[ ";
		for (int num : combination) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	combinations1 = Solution::combinationSum2(nums1, 9);

	std::cout << "[ ";
	for (std::vector<int> combination : combinations1) {
		std::cout << "[ ";
		for (int num : combination) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	combinations2 = Solution::combinationSum2(nums2, 16);

	std::cout << "[ ";
	for (std::vector<int> combination : combinations2) {
		std::cout << "[ ";
		for (int num : combination) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	combinations3 = Solution::combinationSum2(nums3, 5);

	std::cout << "[ ";
	for (std::vector<int> combination : combinations3) {
		std::cout << "[ ";
		for (int num : combination) {
			std::cout << num << ' ';
		}
		std::cout << "] ";
	}
	std::cout << "]\n";
}

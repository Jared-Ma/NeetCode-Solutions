#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static int longestConsecutive(std::vector<int>& nums) {
		std::unordered_set<int> unique_nums {};
		for (int num : nums) {
			unique_nums.insert(num);
		}

		std::unordered_set<int> visited {};
		int max_length = 0;
		for (int num : unique_nums) {
			if (!visited.contains(num)) {
				visited.insert(num);

				int curr = num;
				int forward_length = 0;
				while (unique_nums.contains(++curr)) {
					forward_length++;
					visited.insert(curr);
				}

				curr = num;
				int backward_length = 0;
				while (unique_nums.contains(--curr)) {
					backward_length++;
					visited.insert(curr);
				}

				max_length = std::max(max_length, 1 + forward_length + backward_length);
			}
		}

		return max_length;
	}

	static int longestConsecutive2(std::vector<int>& nums) {
		std::unordered_set<int> unique_nums {};
		for (int num : nums) {
			unique_nums.insert(num);
		}

		// Instead of visited set, only iterate on paths that have no left neighbor
		int max_length = 0;
		for (int num : unique_nums) {
			if (!unique_nums.contains(num - 1)) {
				int length = 1;
				while (unique_nums.contains(num + length)) {
					length++;
				}
				max_length = std::max(max_length, length);
			}
		}

		return max_length;
	}
};

int main() {
	std::vector<int> nums1 {2, 20, 4, 10, 3, 4, 5};
	std::cout << Solution::longestConsecutive(nums1) << '\n';

	std::vector<int> nums2 {0, 3, 2, 5, 4, 6, 1, 1};
	std::cout << Solution::longestConsecutive(nums2) << '\n';

	std::cout << Solution::longestConsecutive2(nums1) << '\n';
	std::cout << Solution::longestConsecutive2(nums2) << '\n';
}
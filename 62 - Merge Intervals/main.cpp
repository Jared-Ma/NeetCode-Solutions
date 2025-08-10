#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
		std::vector<std::vector<int>> merged_intervals {};
		std::sort(
			intervals.begin(), 
			intervals.end(), 
			[](std::vector<int> interval1, std::vector<int> interval2) {
				return interval1[0] < interval2[0];
			}
		);

		std::vector<int> merged_interval = intervals[0];
		for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
			if (merged_interval[1] >= intervals[i][0]) {
				merged_interval[1] = std::max(merged_interval[1], intervals[i][1]);
			} else {
				merged_intervals.push_back(merged_interval);
				merged_interval = intervals[i];
			}
		}
		merged_intervals.push_back(merged_interval);

		return merged_intervals;
	}
};

int main() {
	std::vector<std::vector<int>> intervals1 {{1, 3}, {6, 7}, {1, 5}};
	std::vector<std::vector<int>> merged_intervals1 {Solution::merge(intervals1)};

	std::cout << "[ ";
	for (std::vector<int> interval : merged_intervals1) {
		std::cout << '[' << interval[0] << ", " << interval[1] << "] ";
	}
	std::cout << "]\n";

	std::vector<std::vector<int>> intervals2 {{1, 2}, {2, 3}};
	std::vector<std::vector<int>> merged_intervals2 {Solution::merge(intervals2)};

	std::cout << "[ ";
	for (std::vector<int> interval : merged_intervals2) {
		std::cout << '[' << interval[0] << ", " << interval[1] << "] ";
	}
	std::cout << "]\n";
}
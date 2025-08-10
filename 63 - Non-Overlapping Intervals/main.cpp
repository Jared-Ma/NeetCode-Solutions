#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	static int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
		std::sort(
			intervals.begin(), 
			intervals.end(),
			[](std::vector<int> interval1, std::vector<int> interval2) {
				return interval1[0] < interval2[0];
			}
		);

		int prev_end = intervals[0][1];
		int num_removals = 0;
		for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
			if (prev_end > intervals[i][0]) {
				prev_end = std::min(prev_end, intervals[i][1]);
				++num_removals;
			} else {
				prev_end = intervals[i][1];
			}
		}

		return num_removals;
	}
};

int main() {
	std::vector<std::vector<int>> intervals1 {{1, 2}, {2, 4}, {1, 4}};
	std::cout << Solution::eraseOverlapIntervals(intervals1) << '\n';
	std::vector<std::vector<int>> intervals2 {{1, 2}, {2, 4}};
	std::cout << Solution::eraseOverlapIntervals(intervals2) << '\n';
}
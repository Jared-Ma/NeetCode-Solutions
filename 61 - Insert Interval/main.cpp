#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
		std::vector<std::vector<int>> new_intervals;
		int n = static_cast<int>(intervals.size());

		int i = 0;
		while (i < n && intervals[i][1] < newInterval[0]) {
			new_intervals.push_back(intervals[i]);
			++i;
		}

		while (i < n && newInterval[1] >= intervals[i][0]) {
			newInterval[0] = std::min(newInterval[0], intervals[i][0]);
			newInterval[1] = std::max(newInterval[1], intervals[i][1]);
			++i;
		}
		new_intervals.push_back(newInterval);

		while (i < n) {
			new_intervals.push_back(intervals[i]);
			++i;
		}

		return new_intervals;
	}
};

int main() {
	std::vector<std::vector<int>> intervals1 {{1, 3}, {4, 6}};
	std::vector<int> new_interval1 {2, 5};
	std::vector<std::vector<int>> new_intervals1 = Solution::insert(intervals1, new_interval1);

	std::cout << "[ ";
	for (std::vector<int>& interval : new_intervals1) {
		std::cout << '[' << interval[0] << ", " << interval[1] << "] ";
	}
	std::cout << "]\n";

	std::vector<std::vector<int>> intervals2 {{1, 2}, {3, 5}, {9, 10}};
	std::vector<int> new_interval2 {6, 7};
	std::vector<std::vector<int>> new_intervals2 = Solution::insert(intervals2, new_interval2);

	std::cout << "[ ";
	for (std::vector<int>& interval : new_intervals2) {
		std::cout << '[' << interval[0] << ", " << interval[1] << "] ";
	}
	std::cout << "]\n";
}
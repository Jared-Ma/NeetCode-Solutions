#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
	int start {};
	int end {};
	Interval(int start, int end) : start{start}, end{end} {}
};

class Solution {
public:
	static bool canAttendMeetings(std::vector<Interval>& intervals) {
		std::sort(
			intervals.begin(), 
			intervals.end(), 
			[](const Interval& i1, const Interval& i2) {
				return i1.start < i2.start;
			}
		);

		int num_intervals = static_cast<int>(intervals.size());

		for (int i = 0; i < num_intervals - 1; ++i) {
			if (intervals.data()[i].end > intervals.data()[i + 1].start) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	std::vector<Interval> intervals1 {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
	std::cout << std::boolalpha << Solution::canAttendMeetings(intervals1) << '\n';
	std::vector<Interval> intervals2 {Interval(5, 8), Interval(9, 15)};
	std::cout << std::boolalpha << Solution::canAttendMeetings(intervals2) << '\n';
}
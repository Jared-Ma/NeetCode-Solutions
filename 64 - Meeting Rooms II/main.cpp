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
	static int minMeetingRooms(std::vector<Interval>& intervals) {
		std::vector<int> start_times {};
		std::vector<int> end_times {};

		for (const Interval& interval : intervals) {
			start_times.push_back(interval.start);
			end_times.push_back(interval.end);
		}

		std::sort(start_times.begin(), start_times.end());
		std::sort(end_times.begin(), end_times.end());

		int concurrent_meetings = 0;
		int max_concurrent_meetings = 0;
		int i = 0;
		int j = 0;

		while (i < static_cast<int>(intervals.size())) {
			if (start_times[i] < end_times[j]) {
				++concurrent_meetings;
				++i;
			} else {
				--concurrent_meetings;
				++j;
			}
			max_concurrent_meetings = std::max(max_concurrent_meetings, concurrent_meetings);
		}

		return max_concurrent_meetings;
	}
};

int main() {
	std::vector<Interval> intervals1 {Interval{0, 40}, Interval{5, 10}, Interval{15, 20}};
	std::cout << Solution::minMeetingRooms(intervals1) << '\n';
	std::vector<Interval> intervals2 {Interval{4, 9}};
	std::cout << Solution::minMeetingRooms(intervals2) << '\n';
	std::vector<Interval> intervals2 {Interval{1, 10}, Interval{2, 9}, Interval{3, 8}, Interval{5, 7}, Interval{6, 7}};
	std::cout << Solution::minMeetingRooms(intervals2) << '\n';
}

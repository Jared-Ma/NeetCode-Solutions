#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
	MedianFinder() {}

	void addNum(int num) {
		if (lower_half.size() + upper_half.size() == 0) {
			lower_half.push(num);
		} else if ((lower_half.size() + upper_half.size()) % 2 == 0) {
			if (num <= upper_half.top()) {
				lower_half.push(num);
			} else {
				lower_half.push(upper_half.top());
				upper_half.pop();
				upper_half.push(num);
			}
		} else {
			if (num <= lower_half.top()) {
				upper_half.push(lower_half.top());
				lower_half.pop();
				lower_half.push(num);
			} else {
				upper_half.push(num);
			}
		}
	}

	double findMedian() {
		if ((lower_half.size() + upper_half.size()) % 2 == 0) {
			return (lower_half.top() + upper_half.top()) / 2.0;
		} else {
			return lower_half.top();
		}
	}

private:
	std::priority_queue<int, std::vector<int>, std::less<int>> lower_half {};
	std::priority_queue<int, std::vector<int>, std::greater<int>> upper_half {};
};

int main() {
	MedianFinder medianFinder{};
	medianFinder.addNum(1);
	std::cout << medianFinder.findMedian() << '\n';
	medianFinder.addNum(2);
	std::cout << medianFinder.findMedian() << '\n';
	medianFinder.addNum(3);
	std::cout << medianFinder.findMedian() << '\n';
}
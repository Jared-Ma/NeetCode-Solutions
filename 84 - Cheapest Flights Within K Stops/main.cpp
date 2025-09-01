#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
	static int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
		std::vector<int> costs(n, INT_MAX);
		costs[src] = 0;

		for (int i = 0; i <= k; ++i) {
			std::vector<int> tmp_costs = costs;

			for (std::vector<int> flight : flights) {
				int n1 = flight[0];
				int n2 = flight[1];
				int cost = flight[2];

				if (costs[n1] == INT_MAX) {
					continue;
				}

				if (costs[n1] + cost < tmp_costs[n2]) {
					tmp_costs[n2] = costs[n1] + cost;
				}
			}

			costs = tmp_costs;
		}

		return costs[dst] == INT_MAX ? -1 : costs[dst];
	}
};

int main() {
	std::vector<std::vector<int>> flights1 {
		{0, 1, 200},
		{1, 2, 100},
		{1, 3, 300},
		{2, 3, 100}
	};

	std::cout << Solution::findCheapestPrice(4, flights1, 0, 3, 1) << '\n';
}
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
		std::unordered_map<int, std::vector<std::pair<int, int>>> adjacency_table {};
		for (int i = 0; i < static_cast<int>(times.size()); ++i) {
			adjacency_table[times[i][0]].emplace_back(times[i][1], times[i][2]);
		}
		
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
		min_heap.push({0, k});

		std::unordered_set<int> visited {};
		int max_time = 0;

		while (!min_heap.empty()) {
			int distance = min_heap.top().first;
			int node = min_heap.top().second;
			min_heap.pop();

			if (visited.contains(node)) {
				continue;
			}

			visited.insert(node);

			// Dijkstra's algorithm will visit each node in ascending minimum distances so 
			// the last distance will be the maximum of the minimum distances, which is 
			// equivalent to the minimum time it takes for all nodes to receive the signal
			max_time = distance;

			for (std::pair<int, int> next : adjacency_table[node]) {
				if (!visited.contains(next.first)) {
					min_heap.push({distance + next.second, next.first});
				}
			}
		}

		return visited.size() == n ? max_time : -1;
	}
};

int main() {
	std::vector<std::vector<int>> times1 {
		{1, 2, 1}, {2, 3, 1}, {1, 4, 4}, {3, 4, 1}
	};

	std::cout << Solution::networkDelayTime(times1, 4, 1) << '\n';

	std::vector<std::vector<int>> times2 {
		{1, 2, 1}, {2, 3, 1}
	};

	std::cout << Solution::networkDelayTime(times2, 3, 2) << '\n';

	std::vector<std::vector<int>> times3 {
		{1, 2, 1}, {2, 3, 2}, {1, 3, 2}
	};

	std::cout << Solution::networkDelayTime(times3, 3, 1) << '\n';

	std::vector<std::vector<int>> times4 {
		{2, 4, 10}, {5, 2, 38}, {3, 4, 33}, {4, 2, 76}, 
		{3, 2, 64}, {1, 5, 54}, {1, 4, 98}, {2, 3, 61},
		{2, 1, 0}, {3, 5, 77}, {5, 1, 34}, {3, 1, 79}, 
		{5, 3, 2}, {1, 2, 59}, {4, 3, 46}, {5, 4, 44}, 
		{2, 5, 89}, {4, 5, 21}, {1, 3, 86}, {4, 1, 95}
	};

	std::cout << Solution::networkDelayTime(times4, 5, 1) << '\n';
}
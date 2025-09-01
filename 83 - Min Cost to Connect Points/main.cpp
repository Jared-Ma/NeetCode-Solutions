#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static int minCostConnectPoints(std::vector<std::vector<int>>& points) {
		std::unordered_map<int, std::vector<std::pair<int, int>>> adjacency_table {};
		
		for (int i = 0; i < static_cast<int>(points.size()); ++i) {
			for (int j = i; j < static_cast<int>(points.size()); ++j) {
				int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				adjacency_table[i].push_back({distance, j});
				adjacency_table[j].push_back({distance, i});
			}
		}

		std::priority_queue<
			std::pair<int, int>, 
			std::vector<std::pair<int, int>>, 
			std::greater<std::pair<int, int>>
		> min_heap;
		std::unordered_set<int> visited;
		min_heap.push({0, 0});
		int total_cost = 0;

		while (visited.size() < points.size()) {
			int cost = min_heap.top().first;
			int node = min_heap.top().second;
			min_heap.pop();

			if (visited.contains(node)) {
				continue;
			}

			total_cost += cost;
			visited.insert(node);

			for (const auto& [neighbor_cost, neighbor] : adjacency_table[node]) {
				if (!visited.contains(neighbor)) {
					min_heap.push({neighbor_cost, neighbor});
				}
			}
		}

		return total_cost;
	}
};

int main() {
	std::vector<std::vector<int>> points1 {
		{0, 0}, {2, 2}, {3, 3}, {2, 4}, {4, 2}
	};

	std::cout << Solution::minCostConnectPoints(points1) << '\n';
}
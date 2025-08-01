#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static bool cycle_exists(int parent, int node, std::unordered_set<int>& visited, std::unordered_map<int, std::vector<int>>& neighbor_map) {
		if (visited.contains(node)) {
			return true;
		}

		visited.insert(node);

		bool cycle = false;
		for (int neighbor : neighbor_map[node]) {
			if (neighbor != parent && cycle_exists(node, neighbor, visited, neighbor_map)) {
				cycle = true;
			};
		}
		return cycle;
	}

	static bool validTree(int n, std::vector<std::vector<int>>& edges) {
		std::unordered_set<int> visited {};
		std::unordered_map<int, std::vector<int>> neighbor_map {};

		for (std::vector<int> edge : edges) {
			neighbor_map[edge[0]].push_back(edge[1]);
			neighbor_map[edge[1]].push_back(edge[0]);
		}

		if (cycle_exists(-1, 0, visited, neighbor_map) || n != visited.size()) {
			return false;
		}

		return true;
	}
};

int main() {
	std::vector<std::vector<int>> edges1 {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
	std::cout << std::boolalpha << Solution::validTree(5, edges1) << '\n';
	std::vector<std::vector<int>> edges2 {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
	std::cout << std::boolalpha << Solution::validTree(5, edges2) << '\n';
	std::vector<std::vector<int>> edges3 {{0, 1}, {0, 2}, {2, 3}, {4, 5}};
	std::cout << std::boolalpha << Solution::validTree(6, edges3) << '\n';
}
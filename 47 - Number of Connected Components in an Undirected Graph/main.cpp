#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static void dfs(int node, std::unordered_set<int>& visited, std::unordered_map<int, std::vector<int>>& neighbor_map) {
		if (visited.contains(node)) {
			return;
		}

		visited.insert(node);
		for (int neighbor : neighbor_map[node]) {
			dfs(neighbor, visited, neighbor_map);
		}
	}

	static int countComponents(int n, std::vector<std::vector<int>>& edges) {
		std::unordered_set<int> visited {};
		std::unordered_map<int, std::vector<int>> neighbor_map {};

		for (std::vector<int> edge : edges) {
			neighbor_map[edge[0]].push_back(edge[1]);
			neighbor_map[edge[1]].push_back(edge[0]);
		}

		int num_connected_components = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited.contains(i)) {
				dfs(i, visited, neighbor_map);
				num_connected_components++;
			}
		}

		return num_connected_components;
	}
};

int main() {
	std::vector<std::vector<int>> edges1 {{0, 1}, {0, 2}};
	std::cout << Solution::countComponents(3, edges1) << '\n';
	std::vector<std::vector<int>> edges2 {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
	std::cout << Solution::countComponents(6, edges2) << '\n';
}

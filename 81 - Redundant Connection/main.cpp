#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static bool dfs(
		std::unordered_map<int, std::vector<int>>& adjacency_table,
		int node, 
		int parent, 
		std::unordered_set<int>& visited, 
		int& cycle_start, 
		std::unordered_set<int>& cycle
	) {
		if (visited.contains(node)) {
			cycle_start = node;
			return true;
		}

		visited.insert(node);
		
		for (int neighbor : adjacency_table[node]) {
			if (neighbor == parent) {
				continue;
			}
			if (dfs(adjacency_table, neighbor, node, visited, cycle_start, cycle)) {
				if (cycle_start != -1) {
					cycle.insert(node);
				}
				if (node == cycle_start) {
					cycle_start = -1;
				}
				return true;
			}
		}

		return false;
	}

	static std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
		int num_edges = static_cast<int>(edges.size());

		std::unordered_map<int, std::vector<int>> adjacency_table {};
		for (std::vector<int> edge : edges) {
			adjacency_table[edge[0]].push_back(edge[1]);
			adjacency_table[edge[1]].push_back(edge[0]);
		}

		std::unordered_set<int> visited {};
		int cycle_start = -1;
		std::unordered_set<int> cycle {};
		dfs(adjacency_table, 1, -1, visited, cycle_start, cycle);

		for (int i = num_edges - 1; i >= 0; --i) {
			if (cycle.contains(edges[i][0]) && cycle.contains(edges[i][1])) {
				return edges[i];
			}
		}

		return {};
	}
};

int main() {
	std::vector<std::vector<int>> edges1 {
		{1, 2},
		{1, 3},
		{3, 4},
		{2, 4}
	};

	std::vector<int> edge1 {Solution::findRedundantConnection(edges1)};

	std::cout << "[ " << edge1[0] << ' ' << edge1[1] << " ]\n";

	std::vector<std::vector<int>> edges2 {
		{1, 2},
		{1, 3},
		{1, 4},
		{3, 4},
		{4, 5}
	};

	std::vector<int> edge2 {Solution::findRedundantConnection(edges2)};

	std::cout << "[ " << edge2[0] << ' ' << edge2[1] << " ]\n";
}
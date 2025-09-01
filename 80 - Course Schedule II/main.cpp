#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
	static std::vector<int> findOrder(
		int numCourses, 
		std::vector<std::vector<int>>& prerequisites
	) {
		std::vector<int> degree_table(numCourses, 0);

		std::vector<std::vector<int>> adjacency_table(numCourses);
		for (std::vector<int> prerequisite : prerequisites) {
			adjacency_table[prerequisite[1]].push_back(prerequisite[0]);
			degree_table[prerequisite[0]]++;
		}

		std::queue<int> queue {};
		for (int i = 0; i < numCourses; ++i) {
			if (degree_table[i] == 0) {
				queue.push(i);
			}
		}

		std::vector<int> ordering {};
		while (!queue.empty()) {
			int course = queue.front();
			queue.pop();

			ordering.push_back(course);

			for (int neighbor : adjacency_table[course]) {
				degree_table[neighbor]--;
				if (degree_table[neighbor] == 0) {
					queue.push(neighbor);
				}
			}
		}

		if (static_cast<int>(ordering.size()) != numCourses) {
			return {};
		}

		return ordering;
	}
};

int main() {
	std::vector<std::vector<int>> prerequisites1 {
		{1, 0}
	};

	std::vector<int> ordering1 = Solution::findOrder(3, prerequisites1);

	std::cout << "[ ";
	for (int course : ordering1) {
		std::cout << course << ' ';
	}
	std::cout << "]\n";

	std::vector<std::vector<int>> prequisites2 {
		{0, 1}, {1, 2}, {2, 0}
	};

	std::vector<int> ordering2 = Solution::findOrder(3, prequisites2);

	std::cout << "[ ";
	for (int course : ordering2) {
		std::cout << course << ' ';
	}
	std::cout << "]\n";
}
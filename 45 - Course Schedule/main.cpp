#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
	static bool dfs(
		int course, 
		std::unordered_set<int> visited,
		std::unordered_map<int, std::vector<int>> course_prereq_map
	) {
		if (visited.contains(course)) {
			return false;
		}

		if (course_prereq_map[course].empty()) {
			return true;
		}

		visited.insert(course);

		for (int prereq : course_prereq_map[course]) {
			if (!dfs(prereq, visited, course_prereq_map)) {
				return false;
			}
		}

		course_prereq_map[course].clear();

		return true;
	}

	static bool canFinish(int numCourses, std::vector<std::vector<int>>& prereqs) {
		std::unordered_set<int> visited {};
		std::unordered_map<int, std::vector<int>> course_prereq_map {};

		for (int i = 0; i < numCourses; ++i) {
			course_prereq_map[i] = {};
		}

		for (std::vector<int> prereq : prereqs) {
			course_prereq_map[prereq[0]].push_back(prereq[1]);
		}

		for (int i = 0; i < numCourses; ++i) {
			visited.clear();
			if (!dfs(i, visited, course_prereq_map)) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	std::vector<std::vector<int>> prereqs1 {{0, 1}};
	std::cout << std::boolalpha << Solution::canFinish(2, prereqs1) << '\n';
	std::vector<std::vector<int>> prereqs2 {{0, 1}, {1, 0}};
	std::cout << std::boolalpha << Solution::canFinish(2, prereqs2) << '\n';
	std::vector<std::vector<int>> prereqs3 {{1, 0}, {4, 1}, {3, 2}, {4, 3}};
	std::cout << std::boolalpha << Solution::canFinish(5, prereqs3) << '\n';
}
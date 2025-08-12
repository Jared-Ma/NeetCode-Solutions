#include <iostream>
#include <limits>
#include <unordered_map>
#include <string>

class Solution {
public:
	static std::string minWindow(std::string s, std::string t) {
		std::unordered_map<char, int> t_count_map {};
		for (char c : t) {
			t_count_map[c]++;
		}

		int required_count = static_cast<int>(t.length());

		int best_l = 0;
		int best_r = INT_MAX - 1;

		int l = 0;
		int r = 0;

		while (r < s.length()) {
			if (t_count_map.contains(s[r])) {
				t_count_map[s[r]]--;

				// only decrement required_count if s[r] was needed
				if (t_count_map[s[r]] >= 0) {
					required_count--;
				}
			}

			// shrink window one character at a time until required_count is positive again
			while (required_count <= 0) {
				// update best substring seen so far
				if (r - l + 1 < best_r - best_l + 1) {
					best_l = l;
					best_r = r;
				}

				if (t_count_map.contains(s[l])) {
					t_count_map[s[l]]++;

					// only increment required_count if s[l] was needed
					if (t_count_map[s[l]] > 0) {
						required_count++;
					}
				}
				l++;
			}
			r++;
		}

		return (best_r - best_l + 1 != INT_MAX) ? s.substr(best_l, best_r - best_l + 1) : "";
	}
};

int main() {
	std::string s1 {"OUZODYXAZV"};
	std::string t1 {"XYZ"};
	std::cout << Solution::minWindow(s1, t1) << '\n';
	std::string s2 {"xyz"};
	std::string t2 {"xyz"};
	std::cout << Solution::minWindow(s2, t2) << '\n';
	std::string s3 {"x"};
	std::string t3 {"xy"};
	std::cout << Solution::minWindow(s3, t3) << '\n';
	std::string s4 {"OUZZDYXAZV"};
	std::string t4 {"XYZ"};
	std::cout << Solution::minWindow(s4, t4) << '\n';
	std::string s5 {"OUZODYXAZV"};
	std::string t5 {"XYZZ"};
	std::cout << Solution::minWindow(s5, t5) << '\n';
	std::string s6 {"OUZODYXAZZV"};
	std::string t6 {"XYZZ"};
	std::cout << Solution::minWindow(s6, t6) << '\n';
	std::string s7 {"aaabbbbbcdd"};
	std::string t7 {"abcdd"};
	std::cout << Solution::minWindow(s7, t7) << '\n';
}
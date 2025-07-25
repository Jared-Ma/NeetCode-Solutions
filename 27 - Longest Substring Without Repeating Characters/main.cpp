#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
	static int lengthOfLongestSubstring(std::string s) {
		int l = 0;
		int max_length = 0;
		std::unordered_map<char, int> char_last_index {};
		
		for (int r = 0; r < s.length(); ++r) {
			if (char_last_index.contains(s.data()[r])) {
				l = std::max(l, char_last_index[s.data()[r]] + 1);
			}
			char_last_index[s.data()[r]] = r;
			max_length = std::max(max_length, r - l + 1);
		}

		return max_length;
	}
};

int main() {
	std::string s1 {"zxyzxyz"};
	std::cout << Solution::lengthOfLongestSubstring(s1) << '\n';

	std::string s2 {"abcdaefgh"};
	std::cout << Solution::lengthOfLongestSubstring(s2) << '\n';

	std::string s3 {"abba"};
	std::cout << Solution::lengthOfLongestSubstring(s3) << '\n';
}
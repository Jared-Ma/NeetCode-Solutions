#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
	static int characterReplacement(std::string s, int k) {
		int l = 0;
		int max_frequency = 0;
		int max_length = 0;
		std::unordered_map<char, int> char_counts {};

		for (int r = 0; r < s.length(); ++r) {
			char_counts[s.data()[r]]++;
			max_frequency = std::max(max_frequency, char_counts[s.data()[r]]);

			// while number of characters that are not the most frequent in the
			// current window exceed the max number of replacements allowed
			if ((r - l + 1) - max_frequency > k) {
				char_counts[s.data()[l]]--;
				l++;
			}

			max_length = std::max(max_length, r - l + 1);
		}

		return max_length;
	}
};

int main() {
	std::string s1 = "XYYX";
	std::cout << Solution::characterReplacement(s1, 2) << '\n';

	std::string s2 = "AAABABB";
	std::cout << Solution::characterReplacement(s2, 1) << '\n';

	std::string s3 = "X";
	std::cout << Solution::characterReplacement(s3, 1) << '\n';

	std::string s4 = "";
	std::cout << Solution::characterReplacement(s4, 1) << '\n';

	std::string s5 = "AABACCBC";
	std::cout << Solution::characterReplacement(s5, 2) << '\n';
}
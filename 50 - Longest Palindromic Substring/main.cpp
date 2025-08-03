#include <iostream>
#include <string>

class Solution {
public:
	static std::string longestPalindrome(std::string s) {
		std::string result {};
		
		for (int i = 0; i < s.length(); ++i) {
			// Odd length palindromes
			int l = i;
			int r = i;
			while (l >= 0 && r < s.length() && s[l] == s[r]) {
				if (r - l + 1 > result.length()) {
					result = s.substr(l, r - l + 1);
				}
				l--;
				r++;
			}

			// Even length palindromes
			if (i + 1 < s.length() && s[i] == s[i+1]) {
				l = i;
				r = i + 1;
				while (l >= 0 && r < s.length() && s[l] == s[r]) {
					if (r - l + 1 > result.length()) {
						result = s.substr(l, r - l + 1);
					}
					l--;
					r++;
				}
			}
		}

		return result;
	}
};

int main() {
	std::string s1 {"ababd"};
	std::cout << Solution::longestPalindrome(s1) << '\n';
	std::string s2 {"abbc"};
	std::cout << Solution::longestPalindrome(s2) << '\n';
	std::string s3 {"ccc"};
	std::cout << Solution::longestPalindrome(s3) << '\n';
}
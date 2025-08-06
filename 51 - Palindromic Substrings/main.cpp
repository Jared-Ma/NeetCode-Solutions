#include <iostream>
#include <string>

class Solution {
public:
	static int countSubstrings(std::string s) {
		int num_palindromes {0};

		for (int i = 0; i < s.length(); ++i) {
			// Odd length palindromes
			int l = i;
			int r = i;
			while (l >= 0 && r < s.length() && s[l] == s[r]) {
				l--;
				r++;
				num_palindromes++;
			}

			// Even length palindromes
			if (i + 1 < s.length() && s[i] == s[i+1]) {
				l = i;
				r = i + 1;
				while (l >= 0 && r < s.length() && s[l] == s[r]) {
					l--;
					r++;
					num_palindromes++;
				}
			}
		}

		return num_palindromes;
	}
};

int main() {
	std::string s1 {"abc"};
	std::cout << Solution::countSubstrings(s1) << '\n';
	std::string s2 {"aaa"};
	std::cout << Solution::countSubstrings(s2) << '\n';
}
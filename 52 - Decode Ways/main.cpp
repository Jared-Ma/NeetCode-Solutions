#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
	static int numDecodings(std::string s) {
		std::vector<int> dp(s.length() + 1);
		dp[s.length()] = 1;

		for (int i = static_cast<int>(s.length() - 1); i >= 0; i--) {
			if (s[i] == '0') {
				dp[i] = 0;
			} else {
				dp[i] = dp[i + 1];
				if (i + 1 < s.length() && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
					dp[i] += dp[i + 2];
				}
			}
		}

		return dp[0];
	}
};

int main() {
	std::string s1 {"12"};
	std::cout << Solution::numDecodings(s1) << '\n';
	std::string s2 {"01"};
	std::cout << Solution::numDecodings(s2) << '\n';
	std::string s3 {"226"};
	std::cout << Solution::numDecodings(s3) << '\n';
}
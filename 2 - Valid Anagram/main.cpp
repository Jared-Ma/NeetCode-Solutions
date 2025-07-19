#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    static bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> s_counts {};
        for (int i = 0; i < s.length(); ++i) {
            ++s_counts[s[i]];
            --s_counts[t[i]];
        }

        for (auto i = s_counts.begin(); i != s_counts.end(); ++i) {
            if (i->second != 0) {
                return false; 
            }
        }

        return true;
    }
};

int main() {
    std::string s_1 = "racecar";
    std::string t_1 = "carrace";
    std::cout << std::boolalpha << Solution::isAnagram(s_1, t_1) << '\n';

    std::string s_2 = "jar";
    std::string t_2 = "jam";
    std::cout << std::boolalpha << Solution::isAnagram(s_2, t_2) << '\n';
}
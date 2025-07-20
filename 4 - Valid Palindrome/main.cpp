#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
    static bool isPalindrome(std::string s) {
        int i = 0;
        int j = static_cast<int>(s.length());

        while (i < j) {
            if (std::isalnum(s.data()[i]) && std::isalnum(s.data()[j])) {
                if (std::tolower(s.data()[i]) != std::tolower(s.data()[j])) {
                    return false;
                }
                ++i;
                --j;
            } else {
                if (!std::isalnum(s.data()[i])) {
                    ++i;
                }
                if (!std::isalnum(s.data()[j])) {
                    --j;
                }
            }
        }
        
        return true;
    }
};

int main() {
    std::string s1 = "Was it a car or a cat I saw?";
    std::cout << std::boolalpha << Solution::isPalindrome(s1) << '\n';

    std::string s2 = "tab a cat";
    std::cout << std::boolalpha << Solution::isPalindrome(s2) << '\n';
}
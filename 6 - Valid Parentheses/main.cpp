#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    static bool isValid(std::string s) {
        std::stack<char> stack {};

        for (char c : s) {
            if (!stack.empty() && (c == ')' || c == ']' || c == '}')) {
                char p = stack.top();
                if ((p == '(' && c == ')') || (p == '[' && c == ']') || (p == '{' && c == '}')) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};

int main() {
    std::string s1 = "[]";
    std::cout << std::boolalpha << Solution::isValid(s1) << '\n';

    std::string s2 = "([{}])";
    std::cout << std::boolalpha << Solution::isValid(s2) << '\n';
    
    std::string s3 = "[(])";
    std::cout << std::boolalpha << Solution::isValid(s3) << '\n';
}
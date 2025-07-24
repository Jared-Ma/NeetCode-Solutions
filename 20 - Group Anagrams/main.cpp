#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
	static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		std::vector<std::vector<std::string>> anagrams {};
		std::unordered_map<std::string, std::vector<std::string>> char_frequency_map {};
		
		for (std::string str : strs) {
			std::array<int, 26> char_frequency {};
			for (char c : str) {
				char_frequency[static_cast<size_t>(c - 'a')]++;
			}

			std::string key = std::to_string(char_frequency.data()[0]);
			for (int i = 1; i < 26; ++i) {
				key += ' ' + std::to_string(char_frequency.data()[i]);
			}

			char_frequency_map[key].push_back(str);
		}

		for (const auto& [key, value] : char_frequency_map) {
			anagrams.push_back(value);
		}

		return anagrams;
	}
};

int main() {
	std::vector<std::string> strs1 {"act", "pots", "tops", "cat", "stop", "hat"};
	std::vector<std::vector<std::string>> anagrams1 = Solution::groupAnagrams(strs1);

	std::cout << "[ ";
	for (std::vector<std::string> vec : anagrams1) {
		std::cout << "[ ";
		for (std::string str : vec) {
			std::cout << str << " ";
		}
		std::cout << "] ";
	}
	std::cout << "]\n";


	std::vector<std::string> strs2 {"x"};
	std::vector<std::vector<std::string>> anagrams2 = Solution::groupAnagrams(strs2);

	std::cout << "[ ";
	for (std::vector<std::string> vec : anagrams2) {
		std::cout << "[ ";
		for (std::string str : vec) {
			std::cout << str << " ";
		}
		std::cout << "] ";
	}
	std::cout << "]\n";

	std::vector<std::string> strs3 {""};
	std::vector<std::vector<std::string>> anagrams3 = Solution::groupAnagrams(strs3);

	std::cout << "[ ";
	for (std::vector<std::string> vec : anagrams3) {
		std::cout << "[ ";
		for (std::string str : vec) {
			std::cout << str << " ";
		}
		std::cout << "] ";
	}
	std::cout << "]\n";
}
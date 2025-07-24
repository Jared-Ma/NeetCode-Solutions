#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	static std::string encode(std::vector<std::string>& strs) {
		std::string encoded {};
		for (std::string str : strs) {
			encoded.append(std::to_string(str.size()));
			encoded.push_back(':');
			encoded.append(str);
		}

		return encoded;
	}

	static std::vector<std::string> decode(std::string s) {
		std::vector<std::string> decoded_strs {};

		int i = 0;
		while (i < s.length()) {
			std::string l_str {};
			while (s.data()[i] != ':') {
				l_str.push_back(s.data()[i++]);
			}
			int l = std::stoi(l_str);

			std::string decoded_str {s.substr(static_cast<size_t>(i+1), static_cast<size_t>(l))};
			decoded_strs.push_back(decoded_str);
			i += l + 1;
		}

		return decoded_strs;
	}
};

int main() {
	std::vector<std::string> strs1 = {"abcde", ":123:", "helloworld"};
	std::string encoded_str1 = Solution::encode(strs1);
	std::vector<std::string> decoded_strs1 = Solution::decode(encoded_str1);

	std::cout << "[ ";
	for (std::string str : decoded_strs1) {
		std::cout << str << ' ';
	}
	std::cout << "]\n";

	std::vector<std::string> strs2 = {"neet", "code", "love", "you"};
	std::string encoded_str2 = Solution::encode(strs2);
	std::vector<std::string> decoded_strs2 = Solution::decode(encoded_str2);

	std::cout << "[ ";
	for (std::string str : decoded_strs2) {
		std::cout << str << ' ';
	}
	std::cout << "]\n";

	std::vector<std::string> strs3 = {"we", "say", ":", "yes"};
	std::string encoded_str3 = Solution::encode(strs3);
	std::vector<std::string> decoded_strs3 = Solution::decode(encoded_str3);

	std::cout << "[ ";
	for (std::string str : decoded_strs3) {
		std::cout << str << ' ';
	}
	std::cout << "]\n";

	std::vector<std::string> strs4 = {};
	std::string encoded_str4 = Solution::encode(strs4);
	std::vector<std::string> decoded_strs4 = Solution::decode(encoded_str4);

	std::cout << "[ ";
	for (std::string str : decoded_strs4) {
		std::cout << str << ' ';
	}
	std::cout << "]\n";

	std::vector<std::string> strs5 = {"", ""};
	std::string encoded_str5 = Solution::encode(strs5);
	std::vector<std::string> decoded_strs5 = Solution::decode(encoded_str5);

	std::cout << "[ ";
	for (std::string str : decoded_strs5) {
		std::cout << str << ' ';
	}
	std::cout << "]\n";
}
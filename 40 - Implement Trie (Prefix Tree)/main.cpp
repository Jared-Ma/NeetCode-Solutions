#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Node {
public:
	std::array<Node*, 26> children {};
	bool end_of_word {};

	Node() : end_of_word{false} {
		for (int i = 0; i < 26; ++i) {
			children[i] = nullptr;
		}
	}
};

class PrefixTree {
public:
	PrefixTree() {
		root = new Node();
	}

	~PrefixTree() {
		delete root;
	}

	void insert(std::string_view word) {
		Node* curr = root;
		for (char c : word) {
			int i = c - 'a';
			if (curr->children[i] == nullptr) {
				curr->children[i] = new Node();
			}
			curr = curr->children[i];
		}
		curr->end_of_word = true;
	}

	bool search(std::string_view word) const {
		Node* curr = root;
		for (char c : word) {
			int i = c - 'a';
			if (curr->children[i] == nullptr) {
				return false;
			}
			curr = curr->children[i];
		}
		return curr->end_of_word;
	}

	bool startsWith(std::string_view prefix) const {
		Node* curr = root;
		for (char c : prefix) {
			int i = c - 'a';
			if (curr->children[i] == nullptr) {
				return false;
			}
			curr = curr->children[i];
		}
		return true;
	}

private:
	Node* root {};
};

int main() {
	PrefixTree prefixTree {};
	prefixTree.insert("dog");
	std::cout << std::boolalpha << prefixTree.search("dog") << '\n';    // return true
	std::cout << std::boolalpha << prefixTree.search("do") << '\n';     // return false
	std::cout << std::boolalpha << prefixTree.startsWith("do") << '\n'; // return true
	prefixTree.insert("do");
	std::cout << std::boolalpha << prefixTree.search("do") << '\n';     
}

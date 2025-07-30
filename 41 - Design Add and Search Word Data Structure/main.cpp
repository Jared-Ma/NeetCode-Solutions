#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Node {
public:
	std::array<Node*, 26> children {};
	bool word {};

	Node() : children(nullptr), word{false} {}
};

class WordDictionary {
public:
	WordDictionary() : root{new Node()} {}

	void addWord(std::string_view word) {
		Node* curr = root;
		for (char c : word) {
			int i = c - 'a';
			if (curr->children[i] == nullptr) {
				curr->children[i] = new Node();
			}
			curr = curr->children[i];
		}
		curr->word = true;
	}

	bool search(std::string_view word) {
		return dfs(word, 0, root);
	}

private:
	bool dfs(std::string_view word, int j, Node* node) {
		Node* curr = node;

		for (int i = j; i < word.size(); i++) {
			char c = word[i];
			int k = c - 'a';
			if (c == '.') {
				for (Node* child : curr->children) {
					if (child != nullptr && dfs(word, i + 1, child)) {
						return true;
					}
				}
				return false;
			} else {
				if (curr->children[k] == nullptr) {
					return false;
				}
				curr = curr->children[k];
			}
		}
		return curr->word;
	}

	Node* root {};
};

int main() {
	WordDictionary word_dictionary {};
	word_dictionary.addWord("day");
	word_dictionary.addWord("bay");
	word_dictionary.addWord("may");
	std::cout << std::boolalpha << word_dictionary.search("say") << '\n';
	std::cout << std::boolalpha << word_dictionary.search("day") << '\n';
	std::cout << std::boolalpha << word_dictionary.search(".ay") << '\n';
	std::cout << std::boolalpha << word_dictionary.search("b..") << '\n';
}
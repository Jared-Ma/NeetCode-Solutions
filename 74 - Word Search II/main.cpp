#include <array>
#include <iostream>
#include <unordered_set>
#include <vector>

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

class Solution {
public:
    static void search(
        std::vector<std::vector<char>>& board, 
        std::unordered_set<std::string>& found_words, 
        const PrefixTree& prefix_tree,
        std::string& prefix,
        int y, 
        int x
    ) {
        // Can further optimize by traversing prefix_tree with prefix_node argument
        // instead of appending to prefix and searching prefix_tree each call

        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());

        if (
            y < 0 || y >= m || 
            x < 0 || x >= n || 
            board[y][x] == '#' ||
            !prefix_tree.startsWith(prefix)
        ) {
            return;
        }

        prefix.push_back(board[y][x]);

        if (prefix_tree.search(prefix)) {
            found_words.insert(prefix);
        }

        board[y][x] = '#';

        search(board, found_words, prefix_tree, prefix, y + 1, x);
        search(board, found_words, prefix_tree, prefix, y - 1, x);
        search(board, found_words, prefix_tree, prefix, y, x + 1); 
        search(board, found_words, prefix_tree, prefix, y, x - 1);

        board[y][x] = prefix.back();
        prefix.pop_back();
        return;
    }

    static std::vector<std::string> findWords(
        std::vector<std::vector<char>>& board, 
        std::vector<std::string>& words
    ) {
        std::unordered_set<std::string> found_words {};
    
        PrefixTree prefix_tree {};
        for (std::string word : words) {
            prefix_tree.insert(word);
        }
        std::string prefix {};

        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                search(board, found_words, prefix_tree, prefix, y, x);
                if (found_words.size() == words.size()) {
                    break;
                }
            }
        }

        return std::vector<std::string>(found_words.begin(), found_words.end());
    }
};

int main() {
    std::vector<std::vector<char>> board1 {
        {'a', 'b', 'c', 'd'},
        {'s', 'a', 'a', 't'},
        {'a', 'c', 'k', 'e'},
        {'a', 'c', 'd', 'n'},
    };
    std::vector<std::string> words1 {"bat", "cat", "back", "backend", "stack"};

    std::vector<std::string> found_words1 = Solution::findWords(board1, words1);
    std::cout << "[ ";
    for (std::string word : found_words1) {
        std::cout << word << ' ';
    }
    std::cout << "]\n";

    std::vector<std::vector<char>> board2{
        {'x', 'o'},
        {'x', 'o'}
    };
    std::vector<std::string> words2 {"xoxo"};

    std::vector<std::string> found_words2 = Solution::findWords(board2, words2);
    std::cout << "[ ";
    for (std::string word : found_words2) {
        std::cout << word << ' ';
    }
    std::cout << "]\n";

    std::vector<std::vector<char>> board3{
        {'a'}
    };
    std::vector<std::string> words3 {"a"};

    std::vector<std::string> found_words3 = Solution::findWords(board3, words3);
    std::cout << "[ ";
    for (std::string word : found_words3) {
        std::cout << word << ' ';
    }
    std::cout << "]\n";
}
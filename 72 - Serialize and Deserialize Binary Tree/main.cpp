#include <iostream>
#include <string>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	static void serialize_dfs(TreeNode* root, std::string& data) {
		if (root == nullptr) {
			data.append("*,");
			return;
		}

		data.append(std::to_string(root->val));
		data.push_back(',');
		serialize_dfs(root->left, data);
		serialize_dfs(root->right, data);
	}

	static std::string serialize(TreeNode* root) {
		std::string data {};
		serialize_dfs(root, data);
		return data;
	}

	static TreeNode* deserialize_dfs(std::string data, size_t& i, size_t& delimiter_pos) {
		if (delimiter_pos == data.npos) {
			return nullptr;
		}

		if (data.substr(i, delimiter_pos - i) == "*") {
			return nullptr;
		}

		TreeNode* node = new TreeNode(std::stoi(data.substr(i, delimiter_pos - i)));

		i = delimiter_pos + 1;
		delimiter_pos = data.find(',', i);
		node->left = deserialize_dfs(data, i, delimiter_pos);
		
		i = delimiter_pos + 1;
		delimiter_pos = data.find(',', i);
		node->right = deserialize_dfs(data, i, delimiter_pos);

		return node;
	}

	static TreeNode* deserialize(std::string data) {
		size_t i = 0;
		size_t delimiter_pos = data.find(',');
		return deserialize_dfs(data, i, delimiter_pos);
	}

	static void print_inorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		print_inorder(root->left);
		std::cout << root->val << ' ';
		print_inorder(root->right);
	}
};

int main() {
	TreeNode a5 {5};
	TreeNode a4 {4};
	TreeNode a3 {3, &a4, &a5};
	TreeNode a2 {2};
	TreeNode a1 {1, &a2, &a3};

	Solution::print_inorder(&a1);
	std::cout << '\n';


	std::string serialized_string = Solution::serialize(&a1);
	std::cout << serialized_string << '\n';

	TreeNode* root {Solution::deserialize(serialized_string)};
	Solution::print_inorder(root);
	std::cout << '\n';
}
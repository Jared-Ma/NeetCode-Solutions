#include <iostream>
#include <unordered_map>
#include <vector>

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
	static TreeNode* buildTreeRecurse(std::vector<int>& preorder, std::unordered_map<int, int> node_indexes, int l, int r) {
		if (l > r) {
			return nullptr;
		}

		TreeNode* root = new TreeNode(preorder[0]);
		preorder.erase(preorder.begin());

		int root_index = node_indexes[root->val];

		root->left = buildTreeRecurse(preorder, node_indexes, l, root_index - 1);
		root->right = buildTreeRecurse(preorder, node_indexes, root_index + 1, r);

		return root;
	}

	static TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		std::unordered_map<int, int> node_indexes {};
		
		int n = static_cast<int>(inorder.size());
		for (int i = 0; i < n; ++i) {
			node_indexes[inorder.data()[i]] = i;
		}

		return buildTreeRecurse(preorder, node_indexes, 0, n - 1);
	}

	static void print_preorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		std::cout << root->val << ' ';
		print_preorder(root->left);
		print_preorder(root->right);
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
	std::vector<int> preorder1 {1, 2, 3, 4};
	std::vector<int> inorder1 {2, 1, 3, 4};

	TreeNode* root1 {Solution::buildTree(preorder1, inorder1)};
	Solution::print_preorder(root1);
	std::cout << '\n';
	Solution::print_inorder(root1);
	std::cout << '\n';

	std::vector<int> preorder2 {1};
	std::vector<int> inorder2 {1};

	TreeNode* root2 {Solution::buildTree(preorder2, inorder2)};
	Solution::print_preorder(root2);
	std::cout << '\n';
	Solution::print_inorder(root2);
	std::cout << '\n';
}
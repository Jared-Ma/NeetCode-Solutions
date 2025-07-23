#include <iostream>

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
	static TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) {
			return root;
		}

		TreeNode* temp {root->left};
		root->left = root->right;
		root->right = temp;

		invertTree(root->left);
		invertTree(root->right);

		return root;
	}

	static void print_preorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		std::cout << root->val << ' ';
		print_preorder(root->left);
		print_preorder(root->right);
	}
};

int main() {
	TreeNode g {7};
	TreeNode f {6};
	TreeNode e {5};
	TreeNode d {4};
	TreeNode c {3, &f, &g};
	TreeNode b {2, &d, &e};
	TreeNode a {1, &b, &c};
	
	std::cout << "[ ";
	Solution::print_preorder(&a);
	std::cout << "]\n";

	TreeNode* root = Solution::invertTree(&a);
	
	std::cout << "[ ";
	Solution::print_preorder(root);
	std::cout << "]\n";

	TreeNode j {3};
	TreeNode i {2};
	TreeNode h {1, &i, &j};

	std::cout << "[ ";
	Solution::print_preorder(&h);
	std::cout << "]\n";

	root = Solution::invertTree(&h);

	std::cout << "[ ";
	Solution::print_preorder(root);
	std::cout << "]\n";

	root = Solution::invertTree(nullptr);
}
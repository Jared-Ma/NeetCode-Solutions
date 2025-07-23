#include <algorithm>
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
	static int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return std::max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
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

	std::cout << "Depth: " << Solution::maxDepth(&a) << '\n';

	TreeNode k {4};
	TreeNode j {3, &k, nullptr};
	TreeNode i {2};
	TreeNode h {1, &i, &j};

	std::cout << "[ ";
	Solution::print_preorder(&h);
	std::cout << "]\n";

	std::cout << "Depth: " << Solution::maxDepth(&h) << '\n';

	std::cout << "Depth: " << Solution::maxDepth(nullptr) << '\n';
}
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
	static int dfs(TreeNode* root, int& global_max) {
		if (root == nullptr) {
			return 0;
		}
		// left_max and right_max will hold the the max path sum that includes the 
		// left and right subtrees respectively, or 0 if not including them is greater
		int left_max = std::max(dfs(root->left, global_max), 0);
		int right_max = std::max(dfs(root->right, global_max), 0);

		// max path sum including root can either include both 
		// left and right subtrees, one of the two, or neither
		int local_max = root->val + left_max + right_max;
		global_max = std::max(global_max, local_max);

		// returned sum must be of a connected path where each node can only appear 
		// once i.e only one of the left or right subtrees must be chosen, or neither
		return root->val + std::max(left_max, right_max);
	}
	
	static int maxPathSum(TreeNode* root) {
		int global_max = root->val;
		dfs(root, global_max);
		return global_max;
	}
};

int main() {
	TreeNode a3 {3};
	TreeNode a2 {2};
	TreeNode a1 {1, &a2, &a3};
	std::cout << Solution::maxPathSum(&a1) << '\n';

	TreeNode b6 {-5};
	TreeNode b5 {5};
	TreeNode b4 {15, &b6, nullptr};
	TreeNode b3 {20, &b4, &b5};
	TreeNode b2 {10};
	TreeNode b1 {-15, &b2, &b3};
	std::cout << Solution::maxPathSum(&b1) << '\n';
}
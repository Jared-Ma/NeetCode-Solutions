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
	static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || p == nullptr || q == nullptr) {
			return nullptr;
		}
		
		if (root->val > p->val && root->val > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		} else if (root->val < p->val && root->val < q->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		return root;
	}
};

int main() {
	TreeNode h {2};
	TreeNode g {9};
	TreeNode f {7};
	TreeNode e {4};
	TreeNode d {1, nullptr, &h};
	TreeNode c {8, &f, &g};
	TreeNode b {3, &d, &e};
	TreeNode a {5, &b, &c};

	TreeNode* lca = Solution::lowestCommonAncestor(&a, &b, &c);
	std::cout << lca->val << '\n';

	lca = Solution::lowestCommonAncestor(&a, &b, &e);
	std::cout << lca->val << '\n';

	lca = Solution::lowestCommonAncestor(&a, &f, &g);
	std::cout << lca->val << '\n';
}
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
	static bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		}

		if ((p != nullptr && q != nullptr) && (p->val == q->val)) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}

		return false;
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

	std::cout << std::boolalpha << Solution::isSameTree(&a, &a) << '\n';

	TreeNode i {7};
	TreeNode h {4, &i, nullptr};

	TreeNode k {7};
	TreeNode j {4, nullptr, &k};

	std::cout << std::boolalpha << Solution::isSameTree(&h, &j) << '\n';

	TreeNode n {3};
	TreeNode m {2};
	TreeNode l {1, &m, &n};

	TreeNode q {2};
	TreeNode p {3};
	TreeNode o {1, &p, &q};

	std::cout << std::boolalpha << Solution::isSameTree(&l, &o) << '\n';
}
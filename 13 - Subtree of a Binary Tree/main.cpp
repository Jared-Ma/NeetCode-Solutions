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

	static bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (subRoot == nullptr) {
			return true;
		}

		if (root == nullptr) {
			return false;
		}

		if (isSameTree(root, subRoot)) {
			return true;
		}

		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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
	TreeNode p5 {5};
	TreeNode p4 {4};
	TreeNode p3 {3};
	TreeNode p2 {2, &p4, &p5};
	TreeNode p1 {1, &p2, &p3};

	TreeNode q3 {5};
	TreeNode q2 {4};
	TreeNode q1 {2, &q2, &q3};

	std::cout << std::boolalpha << Solution::isSubtree(&p1, &q1) << '\n';

	TreeNode r6 {6};
	TreeNode r5 {5};
	TreeNode r4 {4, &r6, nullptr};
	TreeNode r3 {3};
	TreeNode r2 {2, &r4, &r5};
	TreeNode r1 {1, &r2, &r3};

	TreeNode s3 {5};
	TreeNode s2 {4};
	TreeNode s1 {2, &s2, &s3};

	std::cout << std::boolalpha << Solution::isSubtree(&r1, &s1) << '\n';
}
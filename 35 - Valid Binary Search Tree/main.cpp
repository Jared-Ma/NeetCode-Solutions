#include <iostream>
#include <limits>

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
	static bool isValidBSTRecurse(TreeNode* root, int lower_bound, int upper_bound) {
		if (root == nullptr) {
			return true;
		} 
		std::cout << root->val << '\n';
		std::cout << "[" << lower_bound << ", " << upper_bound << "]" << '\n';
		
		if (root->val <= lower_bound || root->val >= upper_bound) {
			return false;
		}
		return isValidBSTRecurse(root->left, lower_bound, root->val) && isValidBSTRecurse(root->right, root->val, upper_bound);
	}

	static bool isValidBST(TreeNode* root) {
		return isValidBSTRecurse(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
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

	std::cout << std::boolalpha << Solution::isValidBST(&a) << '\n';

	TreeNode j {3};
	TreeNode i {1};
	TreeNode h {2, &i, &j};

	std::cout << std::boolalpha << Solution::isValidBST(&h) << '\n';

	TreeNode m {3};
	TreeNode l {2};
	TreeNode k {1, &l, &m};

	std::cout << std::boolalpha << Solution::isValidBST(&k) << '\n';
}
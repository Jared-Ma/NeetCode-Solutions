#include <iostream>
#include <stack>

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
	static int kthSmallest(TreeNode* root, int k) {
		std::stack<TreeNode*> nodes {};
		TreeNode* curr = root;

		while (curr != nullptr || !nodes.empty()) {	
			while (curr != nullptr) {
				nodes.push(curr);
				curr = curr->left;
			}

			curr = nodes.top();
			nodes.pop();
			
			k--;
			if (k == 0) {
				return curr->val;
			}

			curr = curr->right;
		}

		return -1;
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

	std::cout << std::boolalpha << Solution::kthSmallest(&a, 3) << '\n';

	TreeNode j {3};
	TreeNode i {1};
	TreeNode h {2, &i, &j};

	std::cout << std::boolalpha << Solution::kthSmallest(&h, 1) << '\n';

	TreeNode n {2};
	TreeNode m {5};
	TreeNode l {3, &n, nullptr};
	TreeNode k {4, &l, &m};

	std::cout << std::boolalpha << Solution::kthSmallest(&k, 4) << '\n';
}
#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	static void reorderList(ListNode* head) {
		if (head == nullptr) {
			return;
		};

		std::vector<ListNode*> nodes;
		ListNode* curr = head;
		while (curr) {
			nodes.push_back(curr);
			curr = curr->next;
		}

		int i = 0;
		int j = static_cast<int>(nodes.size() - 1);
		while (j - i > 1) {
			nodes.data()[i]->next = nodes.data()[j];
			i++;
			nodes.data()[j]->next = nodes.data()[i];
			j--;
		}

		nodes.data()[j]->next = nullptr;
	}
};

int main() {
	ListNode d {3};
	ListNode c {2, &d};
	ListNode b {1, &c};
	ListNode a {0, &b};

	Solution::reorderList(&a);
	ListNode* curr {&a};

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";


	ListNode z = {0};
	Solution::reorderList(&z);
	curr = &z;

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";


	Solution::reorderList(nullptr);
	
	ListNode i {4};
	ListNode h {3, &i};
	ListNode g {2, &h};
	ListNode f {1, &g};
	ListNode e {0, &f};

	Solution::reorderList(&e);
	curr = &e;

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";
}
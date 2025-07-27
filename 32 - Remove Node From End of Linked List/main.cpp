#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	static ListNode* removeNthFromEnd(ListNode* head, int n) {
		int length = 0;
		ListNode* curr = head;
		while (curr != nullptr) {
			curr = curr->next;
			length++;
		}

		int position = length - n;
		if (position == 0) {
			return head->next;
		}

		curr = head;
		for (int i = 0; i < length - 1; i++) {
			if ((i + 1) == position) {
				curr->next = curr->next->next;
				break;
			}
			curr = curr->next;
		}

		return head;
	}
};

int main() {
	ListNode d {3};
	ListNode c {2, &d};
	ListNode b {1, &c};
	ListNode a {0, &b};

	ListNode* head = Solution::removeNthFromEnd(&a, 2);
	ListNode* curr {head};

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";


	ListNode e = {0};
	head = Solution::removeNthFromEnd(&e, 1);
	curr = head;

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";


	head = Solution::removeNthFromEnd(nullptr, 1);
	curr = head;

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << '\n';
		curr = curr->next;
	}
	std::cout << "]\n";
}
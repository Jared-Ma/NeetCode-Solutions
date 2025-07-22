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
	static ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr != nullptr) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
			
		return prev;
	}
};

int main() {
	ListNode d {3};
	ListNode c {2, &d};
	ListNode b {1, &c};
	ListNode a {0, &b};

	ListNode* head = Solution::reverseList(&a);
	ListNode* curr {head};

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";


	ListNode e = {0};
	head = Solution::reverseList(&e);
	curr = head;
	
	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";


	head = Solution::reverseList(nullptr);
	curr = head;

	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << '\n';
		curr = curr->next;
	}
	std::cout << "]\n";
}
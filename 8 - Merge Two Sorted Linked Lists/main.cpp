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
	static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr) {
			return list2;
		} else if (list2 == nullptr) {
			return list1;
		}

		ListNode* head = nullptr;
		ListNode* curr = nullptr;

		if (list1->val <= list2->val) {
			head = list1;
			curr = list1;
			list1 = list1->next;			
		} else {
			head = list2;
			curr = list2;
			list2 = list2->next;
		}

		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val <= list2->val) {
				curr->next = list1;
				list1 = list1->next;
			} else {
				curr->next = list2;
				list2 = list2->next;
			}
			curr = curr->next;
		}

		if (list1 != nullptr) {
			curr->next = list1;
		}

		if (list2 != nullptr) {
			curr->next = list2;
		}

		return head;
	}
};

int main() {
	ListNode c1 {4, nullptr};
	ListNode b1 {2, &c1};
	ListNode a1 {1, &b1};

	ListNode c2 {5, nullptr};
	ListNode b2 {3, &c2};
	ListNode a2 {1, &b2};

	ListNode* curr {&a1};
	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";

	curr = &a2;
	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";

	ListNode* head = Solution::mergeTwoLists(&a1, &a2);

	curr = head;
	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";

	ListNode b3 {2, nullptr};
	ListNode a3 {1, &b3};

	head = Solution::mergeTwoLists(&a3, nullptr);
	
	curr = head;
	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";

	head = Solution::mergeTwoLists(nullptr, nullptr);

	curr = head;
	std::cout << "[ ";
	while (curr != nullptr) {
		std::cout << curr->val << ' ';
		curr = curr->next;
	}
	std::cout << "]\n";
}
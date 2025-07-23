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
	static bool hasCycle(ListNode* head) {
		ListNode* slow {head};
		ListNode* fast {head};

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}

		return false;
	}
};

int main() {
	ListNode d {4, nullptr};
	ListNode c {3, &d};
	ListNode b {2, &c};
	ListNode a {1, &b};

	d.next = &b;

	std::cout << std::boolalpha << Solution::hasCycle(&a) << '\n';

	ListNode f {2, nullptr};
	ListNode e {1, &f};

	std::cout << std::boolalpha << Solution::hasCycle(&e) << '\n';
}
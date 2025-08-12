#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	static void print(ListNode* head) {
		ListNode* curr = head;
		std::cout << "[ ";
		while (curr != nullptr) {
			std::cout << curr->val << ' ';
			curr = curr->next;
		}
		std::cout << "]\n";
	}

	static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		ListNode* min_node = nullptr;
		int min_index = 0;

		for (int i = 0; i < static_cast<int>(lists.size()); ++i) {
			if (min_node == nullptr || (lists[i] != nullptr && min_node->val > lists[i]->val)) {
				min_node = lists[i];
				min_index = i;
			}
		}

		if (min_node != nullptr) {
			lists[min_index] = lists[min_index]->next;
			min_node->next = nullptr;
		}

		ListNode* curr = min_node;
		ListNode* head = min_node;

		while (min_node != nullptr) {
			min_node = nullptr;
			min_index = 0;

			for (int i = 0; i < static_cast<int>(lists.size()); ++i) {
				if (min_node == nullptr || (lists[i] != nullptr && min_node->val > lists[i]->val)) {
					min_node = lists[i];
					min_index = i;
				}
			}

			if (min_node != nullptr) {
				lists[min_index] = lists[min_index]->next;
				curr->next = min_node;
				curr = curr->next;
			}
		}

		return head;
	}

	static ListNode* mergeKListsHeap(std::vector<ListNode*>& lists) {
		auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
		std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> min_heap {};

		for (ListNode* list : lists) {
			if (list != nullptr) {
				min_heap.push(list);
			}
		}

		ListNode* head = nullptr;
		ListNode* curr = nullptr;

		if (min_heap.top() != nullptr) {
			ListNode* min_node = min_heap.top();
			min_heap.pop();
			head = min_node;
			curr = min_node;

			min_node = min_node->next;
			if (min_node != nullptr) {
				min_heap.push(min_node);
			}
		}

		while (!min_heap.empty()) {
			ListNode* min_node = min_heap.top();
			min_heap.pop();
			curr->next = min_node;
			curr = curr->next;

			min_node = min_node->next;
			if (min_node != nullptr) {
				min_heap.push(min_node);
			}
		}

		return head;
	}
};

int main() {
	ListNode a3 {4};
	ListNode a2 {2, &a3};
	ListNode a1 {1, &a2};

	ListNode b3 {5};
	ListNode b2 {3, &b3};
	ListNode b1 {1, &b2};

	ListNode c2 {6};
	ListNode c1 {3, &c2};

	std::vector<ListNode*> list1 {&a1, &b1, &c1};
	ListNode* merged1 = Solution::mergeKLists(list1);
	Solution::print(merged1);

	ListNode d3 {5};
	ListNode d2 {4, &d3};
	ListNode d1 {1, &d2};

	ListNode e3 {4};
	ListNode e2 {3, &e3};
	ListNode e1 {1, &e2};

	ListNode f2 {6};
	ListNode f1 {2, &f2};

	std::vector<ListNode*> list2 {&d1, &e1, &f1};
	ListNode* merged2 = Solution::mergeKLists(list2);
	Solution::print(merged2);
}

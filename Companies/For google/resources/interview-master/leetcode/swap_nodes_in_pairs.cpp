#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *first = NULL, *second = NULL;
        if (!head) return head;
        first = head, second = first->next;
        ListNode *prev = head;
        while (first && second) {
            first->next = second->next;
            second->next = first;
            if (prev == head) head = second;
            else prev->next = second;
            prev = first;
            first = first->next;
            if (first) {
                second = first->next;
            }
            else break;
        }
        return head;
    }
};

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	Solution s;
	ListNode *r = s.swapPairs(head);
	while (r) {
		cout << r->val << endl;
		r = r->next;
	}
	return 0;
}

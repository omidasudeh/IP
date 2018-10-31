/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return head;
        int lastnum = head->val;
        ListNode *p = head;
        ListNode *q = NULL;
        while (p->next) {
            if (p->next->val == lastnum) {
                q = p->next;
                p->next = q->next;
                delete q;
            }
            else p = p->next;
            lastnum = p->val;
        }
        return head;
    }
};

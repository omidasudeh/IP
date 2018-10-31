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
        ListNode *q = NULL, *n = NULL;
        bool hasdup = false;
        while (p) {
            hasdup = false;
            while (p->next && p->next->val == lastnum) {
                q = p->next;
                p->next = q->next;
                delete q;
                hasdup = true;
            }
            if (hasdup) {
                n = p;
                p = p->next;
                delete n;
            }
            else p = p->next;
            if (p) lastnum = p->val;
            else break;
        }
        return head;
    }
};

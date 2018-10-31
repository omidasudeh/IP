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
    ListNode *reverse(ListNode *start, ListNode *end, int k) {
        ListNode *p = start->next;
        ListNode *q = start;
        for (int i = 1; i < k; ++i) {
            ListNode *tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
        }
        return end;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *start = head, *end = NULL;
        if (k == 1) return head;
        ListNode *p = head, *prev = head;
        bool over = false;
        while (p) {
            for (int i = 1; i < k; ++i) {
                if (p->next) p = p->next;
                else {
                    over = true;
                    break;
                }
            }
            if (!over) {
                end = p;
                if (p) p = p->next;
                else p = NULL;
                end = reverse(start, end, k);
                start->next = p;
                if (prev != head) prev->next = end;
                else head = end;
                prev = start;
                start = p;
            }
            else break;
        }
        return head;
    }
};

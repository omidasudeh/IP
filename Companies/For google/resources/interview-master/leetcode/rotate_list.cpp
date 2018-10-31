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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k == 0) return head;
        ListNode **p = &head;
        int n = 0;
        while (*p) {
            ++n;
            p = &((*p)->next);
        }
        while (n != 0 && k > n) k -= n;
        for (int i = 0; i < n - k; ++i) {
            *p = head;
            head = head->next;
            (*p)->next = NULL;
            p = &((*p)->next);
        }
        return head;
    }
};

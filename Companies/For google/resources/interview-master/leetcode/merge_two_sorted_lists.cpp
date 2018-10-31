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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode **tail = &head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {   
                *tail = l1;
                l1 = l1->next;
            }
            else {
                *tail = l2;
                l2 = l2->next;
            }
            tail = &((*tail)->next);
        }
        while (l1) {
            *tail = l1;
            l1 = l1->next;
            tail = &((*tail)->next);
        }
        while (l2) {
            *tail = l2;
            l2 = l2->next;
            tail = &((*tail)->next);
        }
        
        return head;
    }
};

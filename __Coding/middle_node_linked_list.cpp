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
    ListNode* middleNode(ListNode* head) {
        if(head == 0)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=0 && fast->next->next!=0){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next == 0)
            return slow;
        return slow->next;
            
    }
};
/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == 0)
            return head;
        unordered_set<int> uniq;
        ListNode* pre = 0;
        ListNode* cur = head;
        while( cur != 0){
            if(uniq.find(cur->val) != uniq.end())//if already exist
            {
                // cout<<"hi\n";
                pre->next = cur->next;
                delete cur;
                cur = cur->next;
            }
            else{
                // cout<<"bi\n";
                
                uniq.insert(cur->val);
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//version 1 simple delete
/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == 0)
            return 0;
        ListNode* pre = 0;
        ListNode* cur = head;
        while(cur!=0){
            if(cur->val == val){
                if(cur == head){
                    head = cur->next;
                    delete cur;
                    cur = head;
                }
                else if(cur->next!= 0){
                    pre->next = cur->next;
                    delete cur;      
                    cur = pre->next;
                }
                else{
                    pre->next = 0;
                    delete cur;      
                    return head;
                }
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
*/


/*version 2 by swapping*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == 0)
            return 0;
        ListNode* cur = head;
        while(cur!= 0){
            if(head->val == val){ // handle the case in which the ehad is the key
                ListNode* t = head;
                head = head->next;
                delete t;
                cur = head;
            }
            else if(cur->next!=0 && cur->next->val == val){
                 ListNode* t = cur->next;
                 cur->next = (cur->next->next!=0)?cur->next->next:0;
                 delete t;
            }
            else{
                cur = cur->next;                
            }
        }
        
        return head;
    }
};
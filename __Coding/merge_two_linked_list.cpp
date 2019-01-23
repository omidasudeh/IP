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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* list = 0;
        ListNode* p3 = list;
        while(p1!=0 && p2!=0){
            if(p1->val<p2->val){
                if(p3 == 0){
                    p3 = p1;
                    list = p3;
                        
                }else{
                    p3->next = p1;
                    p3 = p3->next;
                }
                p1 = p1->next;
            } 
            else{
                if(p3 == 0){
                    p3 = p2;
                    list = p3;
                }else{
                    p3->next = p2;
                    p3 = p3->next;
                }
                p2 = p2->next;
            }
        }
        if(p1!=0)
            if(p3 == 0){
                    p3 = p1;
                    list = p3;
                        
                }else{
                    p3->next = p1;
                    p3 = p3->next;
                }
        if(p2!=0)
             if(p3 == 0){
                    p3 = p2;
                    list = p3;
                }else{
                    p3->next = p2;
                    p3 = p3->next;
                }
        return list;        
    }
};
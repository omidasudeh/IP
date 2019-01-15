/* 
time : 48min
leetcode: 2. Add Two Numbers (Medium)
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == 0)
            return l2;
        if(l2 == 0)
            return l1;
        ListNode* l1_iter = l1;
        ListNode* l2_iter = l2;
        ListNode* result = 0;
        ListNode* tail = 0;
        int carry = 0;
        int res = 0;
        while(l1_iter != 0 || l2_iter != 0){
            int v1 = 0, v2 = 0;
            if(l1_iter != 0)
                v1 = l1_iter->val;
            if(l2_iter!=0)
                v2 = l2_iter->val; 
            int sum = v1 + v2 + carry;
            carry = sum>9;
            res = (sum)%10;
            ListNode* temp = new ListNode(res);
            if(result == 0){
                result = temp;
                tail = result;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            if(l1_iter != 0)
                l1_iter = l1_iter->next;
            if(l2_iter != 0)
                l2_iter = l2_iter->next;
        }
        if(carry){
             ListNode* temp = new ListNode(1);
             tail->next = temp;
             tail = temp;   
        }
        return result;
    }
};
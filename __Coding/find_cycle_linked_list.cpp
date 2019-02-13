/**
141. Linked List Cycle
Easy

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


 */
 // solution1 : using a visited set
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == 0 || head->next == 0)
            return false;
        unordered_set<ListNode*> visited;
        ListNode* cur = head;
        while(cur){
            if(visited.find(cur)!=visited.end())//if already visited
                return true;
            visited.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};
 // solution2 : constant space, meeting of slow and fast runners
class Solution { // solution1 : using a visited set
public:
    bool hasCycle(ListNode *head) {
        if(head == 0 || head->next == 0)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&slow){
            slow = slow->next;
            if(fast->next && fast->next->next){
                fast = fast->next->next;
                if(fast == slow)
                return true;
            }
        }
        return false;
    }
};
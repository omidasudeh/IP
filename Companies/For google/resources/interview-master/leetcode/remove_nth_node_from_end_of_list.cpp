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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<ListNode*> v = vector<ListNode*>();
        ListNode *p = head;
        while (p) {
            v.push_back(p);
            p = p->next;
        }
        int l = v.size();
        int rp = l - n;
        if (rp > 0) {
            ListNode *tmp = v[rp]->next;
            delete v[rp];
            v[rp - 1]->next = tmp;
        }
        else {
            ListNode *tmp = v[rp]->next;
            delete head;
            head = tmp;
        }
        return head;
    }
};

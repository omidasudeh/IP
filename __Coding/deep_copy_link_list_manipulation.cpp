/*
138. Copy List with Random Pointer
Medium

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == 0) return 0;
        unordered_map<RandomListNode*, RandomListNode*> visited;
        
        RandomListNode* cur = head;
        
        RandomListNode* head1 = new RandomListNode(head->label);
        visited[cur] = head1;
        
        RandomListNode* cur1 = head1;
        if(cur->random == cur)
            cur1->random = cur1;
        while(cur->next!=0){
            if(visited.find(cur->next) == visited.end()){
                RandomListNode* t = new RandomListNode(cur->next->label);
                cur1->next = t;
                visited[cur->next] = t;
                if(cur->random){
                    if(visited.find(cur->random) == visited.end()){
                        t = new RandomListNode(cur->random->label);
                        cur1->random = t;
                        visited[cur->random] = t;
                    }
                    else{
                        cur1->random = visited[cur->random];
                    }
                }
            }
            else{
                cur1->next = visited[cur->next];
                if(cur->random){
                    if(visited.find(cur->random) == visited.end()){
                        RandomListNode* t = new RandomListNode(cur->random->label);
                        cur1->random = t;
                        visited[cur->random] = t;
                    }
                    else{
                        cur1->random = visited[cur->random];
                    }
                }
            }
            cur = cur->next;
            cur1 = cur1->next;
        }
        if(cur->random){
            if(visited.find(cur->random) == visited.end()){
                RandomListNode* t = new RandomListNode(cur->random->label);
                cur1->random = t;
                visited[cur->random] = t;
            }
            else{
                cur1->random = visited[cur->random];
            }
        }
        return head1;    
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>  
using namespace std;
 struct compare  
 {  
   bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)  
   {  
       return p1.first > p2.first;  
   }  
 };  

class Solution {
    private:
        priority_queue<pair<int, int>, vector<pair<int,int>>, compare> min_heap;
    
        
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]!=0)
            {
                min_heap.push(pair<int, int>(lists[i]->val,i));
                lists[i] = lists[i]->next;
            }
        }
        ListNode * result = 0;
        ListNode * tail = 0;
        int i = 0;
        while(!min_heap.empty()){
            // 1.pop min from heap
            pair<int,int> t = min_heap.top();
            min_heap.pop();
            
            // 2.add min to sorted list
            ListNode * newNode = new ListNode(t.first);
            if(tail!=NULL){
                tail->next =newNode;
                tail = tail->next;
            }
            else{ // if the first element
                result = newNode;
                tail = result;
            }
            
            // 3. push next item from the corresponding list to the min heap
            int list_index = t.second;
            ListNode * list = lists[list_index];
            if(list != NULL){
                min_heap.push(pair<int, int>(list->val,list_index));
                lists[t.second] = list->next;
                // delete list;
            }
        }
        return result;
    }
};
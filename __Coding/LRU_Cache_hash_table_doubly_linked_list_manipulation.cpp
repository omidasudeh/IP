/*
146. LRU Cache
Hard

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
struct node{
    int key;
    int val;
    node* next;
    node* previous;
    node(int k, int v):key(k),val(v),next(0), previous (0){}
};
class LRUCache {
private:
    unordered_map<int, node*> map;
    int capacity;
    int count;
    node* head;
    node* tail;
public:
    LRUCache(int c):capacity(c), count(0), head(0), tail(0){
    }
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        else{
            //set it as head as it is touched
            node* t = map[key];
            if(t == head){
                //do nothing
            }
            else if(t == tail){ 
                if (tail->next == head){
                    head = tail;
                    tail = tail->next;
                    tail->previous = 0;
                    head->next = 0;
                    tail->next = head;
                    head->previous = tail;
                }
                else{
                    head->next = tail;
                    tail->previous = head;
                    node* a  = tail->next;
                    head = tail;
                    tail = a;
                    tail->previous = 0;
                    head->next = 0;
                }
            }
            else{
                t->next->previous = t->previous;
                t->previous->next = t->next;
                head->next = t;
                t->previous = head;
                head = t;
            }
            return t->val;
        }
    }
    void put(int key, int value) { 
        // add to head
        // update the map
        if(count<capacity){   //if not full
            if(map.find(key) == map.end()){ //if does not already exist
                //1.  add a new node to head
                node* t = new node(key, value); 
                t->previous = head;
                if(head == 0)
                    head = t;
                else{
                    head->next = t;
                    head = t;
                }
                if(tail == 0)
                    tail = t;
                //2. update the map
                map[key] = t;
                count++;
            }
            else{                           //if already exists: add it to the head of the list; no need to update the map
                //1. take the existed occurance; 
                //2. insert it to the head
                node* t = map[key];
                t->val = value;
                if(t == head){
                    //do nothing
                }
                else if(t == tail){ 
                    if (tail->next == head){
                        head = tail;
                        tail = tail->next;
                        tail->previous = 0;
                        head->next = 0;
                        tail->next = head;
                        head->previous = tail;
                    }
                    else{
                        head->next = tail;
                        tail->previous = head;
                        node* a  = tail->next;
                        head = tail;
                        tail = a;
                        tail->previous = 0;
                        head->next = 0;
                    }
                }
                else{
                    t->next->previous = t->previous;
                    t->previous->next = t->next;
                    head->next = t;
                    t->previous = head;
                    head = t;
                }
            }
        }
        else{//if full
            if(map.find(key) == map.end()){ //if does not already exist
                int expired = tail->key;
                tail->key = key;
                tail->val = value;
                head->next = tail;
                tail->previous = head;
                head = tail;
                tail = tail->next;
                head->next = 0;
                tail->previous = 0;
                //1. update the map
                map.erase(expired);
                map[key] = head;
            }
            else{                           //if already exists
                //1. take the existed occurance; 
                //2. insert it to the head
                node* t = map[key];
                t->val = value;
                if(t == head){
                    //do nothing
                }
                else if(t == tail){ 
                    if (tail->next == head){
                        head = tail;
                        tail = tail->next;
                        tail->previous = 0;
                        head->next = 0;
                        tail->next = head;
                        head->previous = tail;
                    }
                    else{
                        head->next = tail;
                        tail->previous = head;
                        node* a  = tail->next;
                        head = tail;
                        tail = a;
                        tail->previous = 0;
                        head->next = 0;
                    }
                }
                else{
                    t->next->previous = t->previous;
                    t->previous->next = t->next;
                    head->next = t;
                    t->previous = head;
                    head = t;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
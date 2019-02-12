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
class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> map;
    int capacity;
    int count;
    list<pair<int,int>> queue;// a queue of key, val pairs
public:
    LRUCache(int c):capacity(c), count(0){
    }
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        else{
            // remove the current occurance and readd it to the front
            //1.  remove the current occurance from q and map
            int value = map[key]->second;
            queue.erase(map[key]);
            map.erase(key);
            //2. re add to map and queue
            queue.push_front(make_pair(key,value));
            map[key] = queue.begin();
            return value;
        }
    }
    void put(int key, int value) { 
        if(count<capacity){   //if not full
            if(map.find(key) == map.end()){ //if does not already exist
                //1.  add a new node to head
                queue.push_front(make_pair(key,value));
                //2. update the map
                map[key] = queue.begin();
                count++;
            }
            else{                           //if already exists: add it to the head of the list; no need to update the map
                //1. remove it from map and list
                queue.erase(map[key]);
                map.erase(key);
                //2. insert it to the head
                queue.push_front(make_pair(key,value));
                //3. insert to the map
                map[key] = queue.begin();
            }
        }
        else{//if full
            if(map.find(key) == map.end()){ //if does not already exist
                //1. remove tail from queue and remove its entry from map
                int tailKey = queue.back().first;
                queue.pop_back();
                map.erase(tailKey);
                //2. insert to head and update map
                queue.push_front(make_pair(key,value));
                //3. insert to the map
                map[key] = queue.begin();
            }
            else{                           //if already exists
                //1.  remove the current occurance from q and map
                queue.erase(map[key]);
                map.erase(key);
                queue.push_front(make_pair(key,value));
                //2. update the map
                map[key] = queue.begin();
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
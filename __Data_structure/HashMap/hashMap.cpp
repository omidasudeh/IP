#include "hashMap.h"
#include <iostream>
#include <stdexcept>
#include <utility>// for pair data-structure
using namespace std;
/*
The Constructor
    set numer of element to zero
*/
HashMap::HashMap(int capacity = 100):size(0){
    if(capacity == 0){
        __throw_length_error("table capacity is zero");
    }
    table.resize(capacity);
}

/*
The Destructor
    deletes all the buckets' linked-lists
*/
HashMap::~HashMap(){
    for(int i = 0; i<table.size();i++){
        node* cur = table[i];
        while(cur){//delete list of table[i]
            node* next = cur->next;
            delete cur;
            cur = next;
        }
        table[i] = 0;
    }
}

/*
The hash function
*/
int HashMap::hash(int key){
    int table_size = table.size();
    if(table_size == 0){
        __throw_length_error("table capacity is zero");
    }
    return key % (table_size);
}

/*
searchs for an element with key k
*/
node* HashMap::search(int k){
    int index = hash(k);
    node* cur = table[index];
    while(cur)
    {
        if(cur->key == k)//found: return node*
            return cur;
        cur = cur->next;
    }
    return 0; // not found: return NULL
}

/*
inserts an item
*/
void HashMap::insert(node* item){
    if(item == 0) return;
    int index = hash(item->key);
    if(table[index] == 0) // empty bucket: add item
        table[index] = item;
    else{// not empty bucket: add item previous head
        node* head = table[index];
        item->next = head;
        head->previous = item;
        table[index] = item;
    }
}
/*
delete the item from the related bucket list
*/
void HashMap::Delete(node* item){
    if(item == 0) return;
    if(item->previous == 0 && item->next == 0){// if single
        int index = hash(item->key);
        table[index] = 0;
        delete item;
        return;
    }
    if(item->previous == 0 && item->next != 0){// if is head
        int index = hash(item->key);
        table[index] = item->next; // assign head to head->next
        table[index]->previous = 0;// head->next->previous = NULL
        delete item;
        return;
    }
    if(item->previous != 0 && item->next == 0){// if is tail
        item->previous->next = 0;
        delete item;
        return;
    }
    if(item->previous != 0 && item->next != 0){// if item is in middle
        item->previous->next = item->next;
        item->next->previous = item->previous;
        delete item;
        return;
    }
}
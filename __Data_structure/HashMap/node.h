#ifndef NODE_H
#define NODE_H
struct node{
    int key;
    int value;
    node* next;
    node* previous;
    node(int k,int v):key(k), value(v), previous(0),next(0){}
};
#endif
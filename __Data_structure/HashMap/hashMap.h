#include "node.h"
#include <vector>
using namespace std;
#ifndef HASHMAP_H
#define HASHMAP_H
class HashMap
{
  private:
    int size;// number of inserted elements
    vector<node*> table;
    int hash(int);
  public:
  //============ Constructor, Destructor============================
    HashMap(int);
    ~HashMap();
  //============ main operations: insert, delete, search ===========
  void insert (node*);
  void insert (int, int);

  void Delete(node*);
  void Delete(int, int);

  node* search(int);
};
#endif
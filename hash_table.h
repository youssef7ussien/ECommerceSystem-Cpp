#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "linked_list.h"
#include<iostream>

using namespace std;

template <class type>
class Hash {
    List<type> *table;
    int tableSize=26;
public:
    Hash(int);
    void addItem(type);
    void deleteItem(string);
    int hashFunction(string);
    bool search(type &,string);
    bool search(string);
    type getItem(string);
    type operator [](string);
    void displayHash() //for test
    {
      for (int i = 0; i < tableSize; i++) {
        cout<<i<<" - "<<char(i+'a')<<" ";
        for (int j=0 ; j<table[i].getLength() ; j++)
          cout << " --> " << table[i][j].getName();
        cout << endl;
      }
    }
};

#endif // HASHTABLE_H_INCLUDED

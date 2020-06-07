#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "linked_list.h"
#include<iostream>

using namespace std;

template <class type>
class Hash {
    List<type> *table;
    int tableSize;
    int length;
public:
//    Hash(int);
//    void insert(type);
//    void remove(string);
//    int hashFunction(string);
//    bool search(type &,string);
//    bool search(string);
//    type get(string);
//    type operator [](string);

    Hash(int tableSize=26)
    {
        this->tableSize=tableSize;
        table= new List<type>[tableSize];
        length=0;
    }

    int getLength() const
	{
		return length;
	}

    void insert(type item)
    {
        int index=hashFunction(item.getName());
        if(index!=-1)
        {
            table[index].insertLast(item);
            length++;
        }
    }

    void remove(string name)
    {
        int index = hashFunction(name);
        if(index!=-1)
        {
            table[index].remove(name);
            length--;
        }

    }

    int hashFunction(string str)
    {
        if(str[0]>='a' && str[0]<='z')
            return (str[0]-'a');
        else if(str[0]>='A' && str[0]<='Z')
            return (str[0]-'A');
        else
            return -1;
    }

    type *get(string name)
    {
        int index=hashFunction(name);
        return table[index][name];
    }

//    bool search(type &item,string name)
//    {
//        int index=hashFunction(name);
//        if(index!=-1)
//        {
//            item=table[index][name];
//            return true;
//        }
//        return false;
//    }

    bool search(string name)
    {
        int index=hashFunction(name);
        if(index==-1)
            return false;
        return table[index][name] != NULL;
    }

    type *operator [](string name)
    {
        int index=hashFunction(name);
        return table[index][name];
    }

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

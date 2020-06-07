//#include "hash_table.h"
//
//template <class type>
//Hash<type>::Hash(int tableSize)
//{
//    this->tableSize=tableSize;
//    table= new List<type>[tableSize](nullptr);
//}
//
//template <class type>
//void Hash<type>::addItem(type item)
//{
//    int index=hashFunction(item.getName());
//    table[index].insertLast(item);
//}
//
//template <class type>
//void Hash<type>::deleteItem(string name)
//{
//    int index = hashFunction(name);
//    table[index].remove(name);
//
//}
//
//template <class type>
//int Hash<type>::hashFunction(string str)
//{
//    if(str[0]>='a' && str[0]<='z')
//        return (str[0]-'a');
//    else if(str[0]>='A' && str[0]<='Z')
//        return (str[0]-'A');
//    else
//        return -1;
//}
//
//template <class type>
//type Hash<type>::getItem(string name)
//{
//    int index=hashFunction(name);
//    return table[index][name];
//}
//
//template <class type>
//bool Hash<type>::search(type &item,string name)
//{
//    int index=hashFunction(name);
//    if(index!=-1)
//    {
//        item=table[index][name];
//        return true;
//    }
//    return false;
//}
//
//template <class type>
//bool Hash<type>::search(string name)
//{
////    int index=hashFunction(name);
////    if(index==-1)
////        return false;
////    if(table[index][name]!=NULL)
////        return true;
//    return false;
//}
//
//template <class type>
//type Hash<type>::operator [](string name)
//{
//    int index = hashFunction(name);
//    cout<<table[index].searchOf(name)<<endl;
//    return table[index][name];
//}

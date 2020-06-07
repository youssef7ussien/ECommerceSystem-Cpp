#pragma once
#include "../data/linked_list.h"
#include "../data/hash_table.h"
#include "seller.h"

class Sellers
{
    Hash<seller> sellers;
public:
       Sellers()
       {}

       int getLength()
       {
           return sellers.getLength();
       }

       bool isEmpty()
       {
           return sellers.isEmpty();
       }

       void addSeller(Seller seller)
       {
           sellers.insertLast(seller);
       }

       void deleteSeller(int id)
       {
           sellers.remove<int>(id);
       }
};

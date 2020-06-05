#pragma once

#include<iostream>
#include "products.h"
#include "account.h"
#include "categories.h"

using namespace std;

class Seller : public Account
{
    static int count;
    int id;
    Products products;
    Categories categories;
public:

    Seller();
    Seller(string firstName, string lastName, string userName, string email, string password,Products products);
    int getId() const;
    Products getProducts() const;
    Products* getProductsc()
    {
        return &products;
    }
    Product* getProduct(int index);
    Product getProductConst(int index) const // for test
    {
        return products.getProductConst(index);
    }
    Categories getCategories() const;
    bool addProduct(Product item);
    bool updateItemName(int Id,string newName);
    bool updateItemDescription(int Id,string newDescription);
    bool updateItemPrice(int Id,int newPrice);
    bool addCategory(Category Category1);
    bool removeCategory(string name);
    bool addItemToCategory(string name,int itemId);
    bool removeItemFromCategory(string name,int itemId);

};

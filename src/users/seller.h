#pragma once

#include<iostream>
#include "account.h"
#include "../data/linked_list.h"
#include "../data/product.h"

using namespace std;

class Seller : public Account
{
    static int count;
    int id;
    List<int> productsId;
public:

    Seller();
    Seller(string, string, string, string, string, List<int>);
    Seller(string, string, string, string, string);
    int getId() const;
    int numberProducts() const;
    bool addProduct(int);
    bool deleteProduct(int);
    int deleteProductAt(int);
    void getProducts(Product *[],List<Product>);
    int getProductId(int index) const;
    bool operator ==(string) const;
    bool operator !=(string) const;
    bool operator ==(int) const;
    bool operator !=(int) const;

};

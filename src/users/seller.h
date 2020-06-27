#pragma once

#include "account.h"
#include "../data/linked_list.h"
#include "../data/product.h"

class Seller : public Account
{
    static int count;
    int id;
    List<int> productsId;
public:

    Seller();
    Seller(string, string, string, string, string, List<int>);
    Seller(string, string, string, string, string);
//    Seller(const Account &account);
    int getId() const;
    int numberProducts() const;
    void addProductId(int);
    bool deleteProductId(int);
    int deleteProductIdAt(int);
    void getProducts(Product *[],List<Product>);
    int getProductId(int index) const;
    bool operator ==(string) const;
    bool operator !=(string) const;
    bool operator ==(int) const;
    bool operator !=(int) const;

};

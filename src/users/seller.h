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
    explicit Seller(int);
    Seller(const string&, const string&, const string&, const string&, const string&, List<int>);
    Seller(const string&, const string&, const string&, const string&, const string&);
//    Seller(const Account &account);
    int getId() const;
    int numberProducts() const;
    void addProductId(int);
    bool deleteProductId(int);
    int deleteProductIdAt(int);
    void getProducts(Product *[],List<Product>);
    int getProductId(int index) const;
    bool operator ==(const string&) const;
    bool operator !=(const string&) const;
    bool operator ==(int) const;
    bool operator !=(int) const;

};

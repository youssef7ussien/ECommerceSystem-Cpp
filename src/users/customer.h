#ifndef E_COMMERCE_SYSTEM_CUSTOMER_H
#define E_COMMERCE_SYSTEM_CUSTOMER_H

#include "../data/products.h"
#include "account.h"
#include "../data/categories.h"

class Customer : public Account {
    static int count;
    int id;
    Products products;
    Categories categories;
public:
    Customer();
    Customer(string firstName, string lastName, string userName, string email, string password,
            Products products);
    Customer(string firstName, string lastName, string userName, string email, string password,
            Products products, Categories category);
    Categories getCategories() const;
    int getId() const;
    Products getProducts() const;
    Product* getProduct(int);
    Product getProductConst(int index) const // for test
    {
        return products.getProductConst(index);
    }
};


#endif //E_COMMERCE_SYSTEM_CUSTOMER_H

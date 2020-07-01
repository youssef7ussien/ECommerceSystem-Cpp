#ifndef E_COMMERCE_SYSTEM_CUSTOMER_H
#define E_COMMERCE_SYSTEM_CUSTOMER_H

#include "../data/queue.h"
#include "../data/product.h"

using namespace std;

class PurchaseData {

    string name, address, phoneNumber, email, country;

public:

    PurchaseData();
    string getName() const;
    void setName(string);
    string getAddress() const;
    void setAddress(string);
    string getEmail() const;
    void setEmail(string);
    string getPhoneNumber() const;
    void setPhoneNumber(string);
    string getCountry() const;
    void setCountry(string);
    double shippingExpenses(double) const;
    double totalPrice(double) const;
    string getDate();
};

class Customer {

    PurchaseData PD;
    string name;
    Queue<Product> cart;

public:
    Customer();
    explicit Customer(string);
    string getName() const;
    int cartLength() const;
    Queue<Product> getCart() const;
    void clearCart();
    PurchaseData getPurchaseData() const;
    void createPurchaseData(PurchaseData);
    void addToCart(const Product& product);
    Product removeFromCart();
    void printPurchaseData(Queue<Product>);
};


#endif //E_COMMERCE_SYSTEM_CUSTOMER_H

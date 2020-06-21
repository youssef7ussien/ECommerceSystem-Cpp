#ifndef E_COMMERCE_SYSTEM_CUSTOMER_H
#define E_COMMERCE_SYSTEM_CUSTOMER_H

//#include "account.h"
#include "../data/queue.h"
#include "../data/product.h"
#include <iostream>
#include <ctime>
using namespace std;


class PurchaseData {

    string name, address, phoneNumber, email, paymentMethod, country;

public:
    PurchaseData()
    {
        name=address=phoneNumber=email=paymentMethod=country="";
    }

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name=name;
    }

    string getAddress() const
    {
        return address;
    }

    void setAddress(string address)
    {
        this->address=address;
    }

    string getEmail() const
    {
        return email;
    }

    void setEmail(string email)
    {
        this->email=email;
    }

    string getPhoneNumber() const
    {
        return phoneNumber;
    }

    void setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber=phoneNumber;
    }

    string getPaymentMethod() const
    {
        return paymentMethod;
    }

    void setPaymentMethod(string paymentMethod)
    {
        this->paymentMethod=paymentMethod;
    }

    string getCountry() const
    {
        return country;
    }

    void setCountry(string country)
    {
        this->country=country;
    }

    double shippingExpenses(double total1) const
    {
        return 0.05*total1;
    }

    double totalPrice(double total1) const
    {
        return total1-shippingExpenses(total1);
    }

    string getDate()
    {
        time_t now;
        struct tm *nowlacal;
        now=time(nullptr);
        nowlacal=localtime(&now);
        return asctime(nowlacal);
    }


};

class Customer {

    PurchaseData PD;
    string name;
    Queue<Product> cart;

public:
    Customer()
    {
        name="";
    }

    Customer(string name)
    {
        this->name=name;
    }

    string getName() const
    {
        return name;
    }

    int cartLength() const
    {
        return cart.getLength();
    }

    Queue<Product>* getCart()
    {
        return &cart;
    }

    void createPurchaseData(PurchaseData PD)
    {
        this->PD=PD;
    }

    void addToCart(Product product)
    {
        cart.enqueue(product);
    }

    void printPurchaseData()
    {

    }

};


#endif //E_COMMERCE_SYSTEM_CUSTOMER_H

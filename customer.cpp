#include "customer.h"

int Customer::count=0;

Customer::Customer() : Account()
{}

Customer::Customer(string firstName, string lastName, string userName, string email, string password,
Products products) : Account(firstName,lastName,userName,email,password)
{
    id=count++;
    this->products=products;
}

Customer::Customer(string firstName, string lastName, string userName, string email, string password,
Products products, Categories category) : Account(firstName,lastName,userName,email,password)
{
    id=count++;
    this->products=products;
    this->categories=category;
}

int Customer::getId() const
{
    return id;
}

Products Customer::getProducts() const
{
    return products;
}

Product* Customer::getProduct(int index)
{
    return products[index];
}

Categories Customer::getCategories() const
{
    return categories;
}

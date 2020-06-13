#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class Product {
	int id;
	string name, categoryName, description;
	double price;
    static int count;
public:

    Product();
    Product(string name, string categoryName , double price, string description);
	bool operator ==(Product product) const;
	bool operator !=(Product product) const;
	bool operator ==(int id) const;
	bool operator !=(int id) const;
	bool operator ==(string name) const;
	bool operator !=(string name) const;
	int generateId();
	int getId() const;
	string getName() const;
	string getCategoryName() const;
	double getPrice() const;
	string getDescription() const;
	void setName(string newName);
	void setCategoryName(string categoryName);
	void setPrice(double price2);
	void setDescription(string description);
};

#endif // PRODUCT_H_INCLUDED

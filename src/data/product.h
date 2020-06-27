#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class Product {
	int id,quantity;
	string name, categoryName, description;
	double price;
    static int count;
public:

    Product();
    Product(string, string, double, string);
    Product(string, string, double, int, string);
    Product(int, string, string, double, int, string);
    bool outOfStock() const;
    bool decreaseStock();
    void increaseStock();
	int generateId();
	int getId() const;
	void setName(string);
	string getName() const;
	void setPrice(double);
	double getPrice() const;
	void setQuantity(int);
	int getQuantity() const;
	void setCategoryName(string);
	string getCategoryName() const;
	void setDescription(string);
	string getDescription() const;
	bool operator ==(Product) const;
	bool operator !=(Product) const;
	bool operator ==(int) const;
	bool operator !=(int) const;
	bool operator ==(string) const;
	bool operator !=(string) const;
};

#endif // PRODUCT_H_INCLUDED

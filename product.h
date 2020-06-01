#pragma once
#include<iostream>
#include<string>

using namespace std;

class Product {
	int id;
	string name, categoryName, description;
	double price;
public:
	static int count;
    Product()
    {}

    Product(string name, string categoryName , double price, string description)
	{
		this->name = name;
        this->categoryName = categoryName;
        this->price = price;
        this->description = description;
		count++;
		id = count;
	}

	bool operator ==(Product product) const
	{
		return (product.name == name && product.categoryName == categoryName &&
                product.price == price && product.description == description && product.id == id);
	}

	bool operator !=(Product product) const
	{
		return (product.name != name && product.categoryName != categoryName &&
                product.price != price && product.description != description && product.id != id);
	}

	bool operator ==(int id) const
	{
		return ( this->id == id);
	}

	bool operator !=(int id) const
	{
		return (this->id != id);
	}

	bool operator ==(string name) const
	{
		return (this->name == name);
	}

	bool operator !=(string name) const
	{
		return (this->name != name);
	}

	friend istream& operator >>(istream& input, Product& item2)  //for test
	{
		cout << "enter price: ";
		input >> item2.price;
		cout << "enter name: ";
		input >> item2.name;
		cout << "enter category Name: ";
		input >> item2.categoryName;
		cout << "enter description: ";
		getline(input, item2.description);
		getline(input, item2.description);
		count++;
		item2.id = count;

		return input;
	}

	friend ostream& operator <<(ostream& output, Product& item2)  //for test
	{

		output << "price: " << item2.price << "\nname: " << item2.name << "\ncategory Name: "
		<< item2.categoryName << "\ndescription: " << item2.description << "\nid: " << item2.id<<endl;
		output << "-------------------------------------------" <<endl;
		return output;
	}

	int getId() const
	{
		return id;
	}

	string getName() const
	{
		return name;
	}

	string getCategoryName() const
	{
		return categoryName;
	}

	double getPrice() const
	{
		return price;
	}

	string getDescription() const
	{
		return description;
	}

	void setName(string newName)
	{
        name = newName;
	}

	void setCategoryName(string categoryName)
	{
		this->categoryName = categoryName;
	}

	void setPrice(double price2)
	{
        this->price = price2;
	}

	void setDescription(string description)
	{
        this->description = description;
	}

};
int Product::count=-1;

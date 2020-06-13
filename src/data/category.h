#pragma once
#include<iostream>
#include<string>
#include"category.h"
#include"linked_list.h"

using namespace std;

class Category {
	string name;
	List<int> productsId;
public:

    Category()
    {}

    Category(string name,int id)
    {
        this->name=name;
        addProductId(id);
    }

	int numberProducts() const
	{
		return productsId.getLength();
	}

	string getName() const
	{
		return name;
	}

	void setName(string name)
	{
		this->name=name;
	}

	int getProductId(int index) const
	{
		return productsId.getCopyItem(index);
	}

	List<int> getProductsId() const
	{
		return productsId;
	}

	void addProductId(int id)
	{
		productsId.insertLast(id);
	}

	bool deleteProductId(int id)
	{
		return productsId.remove<int>(id);
	}

	bool operator ==(Category category)
	{
		return (category.name==name);
	}

	bool operator !=(Category category)
	{
		return (category.name != name);
	}

	bool operator ==(string name)
	{
		return (this->name == name);
	}

	bool operator !=(string name)
	{
		return (this->name != name);
	}

	int operator [](int index)
	{
		return *productsId[index];
	}
};

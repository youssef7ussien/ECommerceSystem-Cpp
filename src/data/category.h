#pragma once
#include<iostream>
#include<string>
#include"category.h"
#include"linked_list.h"

using namespace std;

class Category {
	string name;
	List<int> itemsId;
public:

    Category()
    {}

    Category(string name,int id)
    {
        this->name=name;
        addProductId(id);
    }

	int getNumberItems()
	{
		return itemsId.getLength();
	}

	void setName(string name)
	{
		this->name=name;
	}

	string getName()
	{
		return name;
	}

	int getProductId(int index)
	{
		return itemsId.getCopyItem(index);
	}

	void addProductId(int id)
	{
		itemsId.insertLast(id);
	}

	bool deleteProductId(int id)
	{
		return itemsId.remove<int>(id);
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
};

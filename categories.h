#pragma once

#include"category.h"
class Categories {

	List<Category> categories;
public:
	void addCategory(Category newCategory)
	{
		categories.insertLast(newCategory);
	}

	void removeCategory(string name)
	{
		categories.remove(name);
	}

	int getLength()
	{
		return categories.getLength();
	}

	Category *getCategory(string name)
	{
		return categories[name];
	}

	Category *operator [](string name)
	{
		return categories[name];
	}

	Category *operator [](int index)
	{
		return categories[index];
	}

};

#pragma once
#include"category.h"
#include "hash_table.h"

class Categories {
	Hash<Category> categories;
public:


	int getLength() const
	{
		return categories.getLength();
	}

	void addCategory(Category category)
	{
		categories.insert(category);
	}

	void removeCategory(string name)
	{
		categories.remove(name);
	}

	bool searchCategory(string name)
	{
	    if(getLength()==0)
            return false;
	    return categories.search(name);
	}

	Category *getCategory(string name)
	{
		return categories.get(name);
	}

	Category *operator [](string name)
	{
		return categories[name];
	}
//
//	Category *operator [](int index)
//	{
//		return categories[index];
//	}

};

#pragma once
#include"category.h"
#include "hash_table.h"

class Categories {
	List<Category> categories;
public:


	int getLength() const
	{
		return categories.getLength();
	}

	void addCategory(Category category)
	{
		categories.insertLast(category);
	}

	void removeCategory(string name)
	{
		categories.remove<string>(name);
	}

	bool searchCategory(string name)
	{
	    if(getLength()==0)
            return false;
	    return categories.search<string>(name);
	}

    Category getCategoryConst(int index) const
	{
		return categories.getCopyItem(index);
	}

	Category *getCategory(string name)
	{
		return categories.getItem(name);
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

#pragma once
#include"linked_list.h"
#include"product.h"
class Products {
	List<Product> products;
public:

	Product *getProduct(string name)
	{
		return products.getItem(name);
	}

	Product *getProduct(int id)
	{
		return products.getItem(id);
	}

	Product getProductConst(int index) const
	{
		return products.getCopyItem(index);
	}

	int getLength() const
	{
		return products.getLength();
	}

	bool deleteProduct(int id)
	{
		return products.remove<int>(id);
	}

	bool deleteProductAt(int index)
	{
		return products.removeAt(index);
	}

	void addProduct(Product product)
	{
		products.insertLast(product);
	}

	void updateCategory(int id,string newCategory)
	{
		products.search(id).setCategoryName(newCategory);
	}

	void updateName(int id, string newName)
	{
		products.search(id).setName(newName);
	}

	void updateDescription(int id, string newDescription)
	{
		products.search(id).setDescription(newDescription);
	}

	void updatePrice(int id, double newPrice)
	{
		products.search(id).setPrice(newPrice);
	}

	Product *operator [](int index)
	{
		return products[index];
	}
};

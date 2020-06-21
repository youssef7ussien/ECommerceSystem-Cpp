#pragma once
#include"linked_list.h"
#include"product.h"
#include"category.h"

class Products {

	List<Product> products;
	List<Category> categories;

	void deleteFromCategory(int id,string name)
	{
	    Category *category=categories[name];
	    category->deleteProductId(id);
	    if(!category->numberProducts())
            categories.remove<string>(category->getName());
	}

    bool searchCategory(string name)
	{
	    if(categories.getLength()==0)
            return false;
	    return categories.contain<string>(name);
	}

public:
    Products()
    {}

    void initializingData()
    {
        addProduct(Product("Apple MacBook Pro 2019", "Laptops",         2579.58, "There is no description"));
        addProduct(Product("Nokia 105",              "Mobile Phones",   115.00,  "There is no description"));
        addProduct(Product("FIFA 20 PlayStation 4",  "Video Games",     56.80,   "There is no description"));
        addProduct(Product("Apple iPhone XS Max",    "Mobile Phones",   999.00,  "There is no description"));
        addProduct(Product("SanDisk 128GB Ultra",    "Computer",        20.99,   "There is no description"));
        addProduct(Product("Artificial Flowers",     "Flowers",         3.58,    "There is no description"));
        addProduct(Product("Samsung Galaxy S20+",    "Mobile Phones",   999.99,  "There is no description"));
        addProduct(Product("VR Box 3D",              "Virtual Reality", 7.45,    "There is no description"));
        addProduct(Product("HP 107a Laser Printer",  "Printer",         77.72,   "There is no description"));
        addProduct(Product("UNO Playing Cards Game", "Toys",            7.65,    "There is no description"));
        addProduct(Product("Golden Play Cards",      "Toys",            3.55,    "There is no description"));
        addProduct(Product("Pioneer MVHS105UI Car",  "Car Audio",       8.45,    "There is no description"));
        addProduct(Product("Samsung Galaxy S8",      "Mobile Phones",   499.99,  "There is no description"));
        addProduct(Product("Sky blue necklace",      "Necklaces",       5.00,    "There is no description"));
        addProduct(Product("Quiz Bodycon Dress",     "Clothes",         18.45,   "There is no description"));
        addProduct(Product("Ravin A Line Skirt",     "Clothes",         23.95,   "There is no description"));
        addProduct(Product("Loose Face Powder",      "Makeup",          23.95,   "There is no description"));
        addProduct(Product("Tekken 7 ",           "Video Games",        23.95,   "There is no description"));
        addProduct(Product("Tekken 8",           "Video Games",         35.95,   "There is no description"));
        addProduct(Product("Tekken 10",           "Video Games",        42.95,   "There is no description"));
        addProduct(Product("Tekken 11",           "Video Games",        58.95,   "There is no description"));
    }

	int categoriesLength() const
	{
		return categories.getLength();
	}

	int productsLength() const
	{
		return products.getLength();
	}

	Product *getProduct(int id)
	{
		return products.getItem(id);
	}

	Product getProductConst(int index) const
	{
		return products.getCopyItem(index);
	}

	Product getProductConstId(int id) const
	{
		return products.getItemId(id);
	}

	List<Product> getProducts() const
	{
		return products;
	}

	List<Category> getCategories() const
	{
		return categories;
	}

	List<Product> getProductsOfCategory(List<int> productsId) const
	{
		List<Product> pro;
		for(int i=0 ; i<productsId.getLength() ; i++)
            pro.insertLast(products.getItemId(*productsId[i]));
        return pro;
	}

	Category *getCategory(int index)
	{
		return categories[index];
	}

	Category getCategoryConst(int index) const
	{
		return categories.getCopyItem(index);
	}

	void addProduct(Product product)
	{
	    if(!searchCategory(product.getCategoryName()))
            categories.insertLast(Category(product.getCategoryName(),product.getId()));
        else
            categories[product.getCategoryName()]->addProductId(product.getId());

		products.insertLast(product);
	}

	bool deleteProduct(int id)
	{
	    deleteFromCategory(id,products.getItem(id)->getCategoryName());
		return products.remove<int>(id);
	}

	bool deleteProductAt(int index)
	{
	    Product product=products.getCopyItem(index);
	    deleteFromCategory(product.getId(),product.getCategoryName());
		return products.removeAt(index);
	}

};


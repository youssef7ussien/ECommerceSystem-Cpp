#pragma once
#include"linked_list.h"
#include"product.h"
#include"category.h"

class Products {

	List<Product> products;
	List<Category> categories;
	void deleteFromCategory(int,string);
    bool searchCategory(string );

public:
    Products();
	int categoriesLength() const;
	int productsLength() const;
	Product& getHead()
	{
		return products.getHead();
	}

	Product* getProduct(int);
	Product* getProductAt(int);
	Product getCopyProductAt(int) const;
	Product getCopyProduct(int) const;
	List<Product> getProducts() const;
	Category *getCategory(int);
	Category getCopyCategoryAt(int) const;
	List<Product> getProductsOfCategory(List<int>) const;
	List<Category> getCategories() const;
	void changeCategory(int,string,const string&);
	void addProduct(const Product&);
	bool deleteProduct(int);
	bool deleteProductAt(int);

    void defaultData();  // For Test
    bool initializingData();
    bool saveData();
};


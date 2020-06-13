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
    {
        addProduct(Product("ihussien","ea1",100.5,"hgfghfghgfgghg"));
        addProduct(Product("mahmoud","za2",35.3,"hgfghfgfghfghgfghghgfghfgh"));
        addProduct(Product("Jesekka","ea1",35.3,"hgfghfghggfhfghgfghf"));
        addProduct(Product("soliman","ea1",98.75,"hgfghfg"));
        addProduct(Product("youssef","za1",64.25,"hgfghfg"));
        addProduct(Product("Ahmed","hg3",94.5,"hgfghfg"));
        addProduct(Product("Salem","sa2",684.3,"hgfghfg"));
        addProduct(Product("Metwally","hgjhgj",25.45,"hgfghfg"));
        addProduct(Product("Shehab","iu",154.72,"hgfghfg"));
        addProduct(Product("Oraby","hf",987.5,"hgfghfg"));
        addProduct(Product("Hussien","nb",9521.78,"hgfghfg"));
        addProduct(Product("Sayed","mju",1025.45,"hgfghfg"));
        addProduct(Product("Ali","hn",492.3,"hgfghfg"));
        addProduct(Product("Nady","mju",1278.52,"hgfghfg"));
        addProduct(Product("Sayed","gvc",1025.45,"hgfghfg"));
//        addProduct(Product("Ali","dew",492.3,"hgfghfg"));
//        addProduct(Product("Nady","sxz",1278.52,"hgfghfg"));
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

//	Product searchProduct(string name)
//	{
//		return products.search<string>(name);
//	}

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


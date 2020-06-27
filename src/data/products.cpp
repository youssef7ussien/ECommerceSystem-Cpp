#include "products.h"

Products::Products()
{}

void Products::deleteFromCategory(int id,string name)
{
    Category *category=categories[name];
    category->deleteProductId(id);
    if(!category->numberProducts())
        categories.remove<string>(category->getName());
}

bool Products::searchCategory(string name)
{
    if(categories.getLength()==0)
        return false;
    return categories.contain<string>(name);
}

void Products::initializingData()
{
    addProduct(Product("Apple MacBook Pro 2019", "Laptops",         2579.58, 0, "There is no description"));
    addProduct(Product("Nokia 105",              "Mobile Phones",   115.00,  1, "There is no description"));
    addProduct(Product("FIFA 20 PlayStation 4",  "Video Games",     56.80,   0, "There is no description"));
    addProduct(Product("Apple iPhone XS Max",    "Mobile Phones",   999.00,  0, "There is no description"));
    addProduct(Product("SanDisk 128GB Ultra",    "Computer",        20.99,   2, "There is no description"));
    addProduct(Product("Artificial Flowers",     "Flowers",         3.58,    0, "There is no description"));
    addProduct(Product("Samsung Galaxy S20+",    "Mobile Phones",   999.99,  0, "There is no description"));
    addProduct(Product("VR Box 3D",              "Virtual Reality", 7.45,    3, "There is no description"));
    addProduct(Product("HP 107a Laser Printer",  "Printer",         77.72,   0, "There is no description"));
    addProduct(Product("UNO Playing Cards Game", "Toys",            7.65,    0, "There is no description"));
    addProduct(Product("Golden Play Cards",      "Toys",            3.55,    2, "There is no description"));
    addProduct(Product("Pioneer MVHS105UI Car",  "Car Audio",       8.45,    0, "There is no description"));
    addProduct(Product("Samsung Galaxy S8",      "Mobile Phones",   499.99,  1, "There is no description"));
    addProduct(Product("Sky blue necklace",      "Necklaces",       5.00,    0, "There is no description"));
    addProduct(Product("Quiz Bodycon Dress",     "Clothes",         18.45,   0, "There is no description"));
    addProduct(Product("Ravin A Line Skirt",     "Clothes",         23.95,   0, "There is no description"));
    addProduct(Product("Loose Face Powder",      "Makeup",          23.95,   0, "There is no description"));
    addProduct(Product("Tekken 7 ",           "Video Games",        23.95,   0, "There is no description"));
    addProduct(Product("Tekken 8",           "Video Games",         35.95,   4, "There is no description"));
    addProduct(Product("Tekken 10",           "Video Games",        42.95,   0, "There is no description"));
    addProduct(Product("Tekken 11",           "Video Games",        58.95,   1, "There is no description"));
}

int Products::categoriesLength() const
{
    return categories.getLength();
}

int Products::productsLength() const
{
    return products.getLength();
}

Product* Products::getProduct(int id)
{
    return products.getItem(id);
}

Product* Products::getProductAt(int index)
{
    return products[index];
}

Product Products::getCopyProductAt(int index) const
{
    return products.getCopyItemAt(index);
}

Product Products::getCopyProduct(int id) const
{
    return products.getCopyItem(id);
}

List<Product> Products::getProducts() const
{
    return products;
}

Category* Products::getCategory(int index)
{
    return categories[index];
}

Category Products::getCopyCategoryAt(int index) const
{
    return categories.getCopyItemAt(index);
}

List<Product> Products::getProductsOfCategory(List<int> productsId) const
{
    List<Product> pro;
    for(int i=0 ; i<productsId.getLength() ; i++)
        pro.insertLast(products.getCopyItem(*productsId[i]));
    return pro;
}

List<Category> Products::getCategories() const
{
    return categories;
}

void Products::changeCategory(int productId,string oldCategoryName,string newCategoryName)
{
    deleteFromCategory(productId,oldCategoryName);
    if(!searchCategory(newCategoryName))
        categories.insertLast(Category(newCategoryName,productId));
    else
        categories[newCategoryName]->addProductId(productId);
}

void Products::addProduct(Product product)
{
    if(!searchCategory(product.getCategoryName()))
        categories.insertLast(Category(product.getCategoryName(),product.getId()));
    else
        categories[product.getCategoryName()]->addProductId(product.getId());

    products.insertLast(product);
}

bool Products::deleteProduct(int id)
{
    deleteFromCategory(id,products.getItem(id)->getCategoryName());
    return products.remove<int>(id);
}

bool Products::deleteProductAt(int index)
{
    Product product=products.getCopyItemAt(index);
    deleteFromCategory(product.getId(),product.getCategoryName());
    return products.removeAt(index);
}

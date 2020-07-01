#include <fstream>
#include <cstring>
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
    List<Product> productsCategory;
    for(int i=0 ; i<productsId.getLength() ; i++)
        productsCategory.insertLast(products.getCopyItem(*productsId[i]));
    return productsCategory;
}

List<Category> Products::getCategories() const
{
    return categories;
}

void Products::changeCategory(int productId,string oldCategoryName,const string &newCategoryName)
{
    deleteFromCategory(productId,oldCategoryName);
    if(!searchCategory(newCategoryName))
        categories.insertLast(Category(newCategoryName,productId));
    else
        categories[newCategoryName]->addProductId(productId);
}

void Products::addProduct(const Product& product)
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

void Products::defaultData() // For Test
{
    addProduct(Product("Apple MacBook Pro 2019", "Laptops",         2579.58, 5, "There is no description"));
    addProduct(Product("Nokia 105",              "Mobile Phones",   115.00,  0, "There is no description"));
    addProduct(Product("FIFA 20 PlayStation 4",  "Video Games",     56.80,   0, "There is no description"));
    addProduct(Product("Apple iPhone XS Max",    "Mobile Phones",   999.00,  9, "There is no description"));
    addProduct(Product("SanDisk 128GB Ultra",    "Computer",        20.99,   2, "There is no description"));
    addProduct(Product("Artificial Flowers",     "Flowers",         3.58,    0, "There is no description"));
    addProduct(Product("Samsung Galaxy S20+",    "Mobile Phones",   999.99,  0, "There is no description"));
    addProduct(Product("VR Box 3D",              "Virtual Reality", 7.45,    3, "There is no description"));
    addProduct(Product("HP 107a Laser Printer",  "Printer",         77.72,   0, "There is no description"));
    addProduct(Product("UNO Playing Cards Game", "Toys",            7.65,    7, "There is no description"));
    addProduct(Product("Golden Play Cards",      "Toys",            3.55,    2, "There is no description"));
    addProduct(Product("Pioneer MVHS105UI Car",  "Car Audio",       8.45,    0, "There is no description"));
    addProduct(Product("Samsung Galaxy S8",      "Mobile Phones",   499.99,  1, "There is no description"));
    addProduct(Product("Sky blue necklace",      "Necklaces",       5.00,    0, "There is no description"));
    addProduct(Product("Quiz Bodycon Dress",     "Clothes",         18.45,   5, "There is no description"));
    addProduct(Product("Ravin A Line Skirt",     "Clothes",         23.95,   8, "There is no description"));
    addProduct(Product("Loose Face Powder",      "Makeup",          23.95,   0, "There is no description"));
    addProduct(Product("Tekken 7 ",           "Video Games",        23.95,   9, "There is no description"));
    addProduct(Product("Tekken 8",           "Video Games",         35.95,   4, "There is no description"));
    addProduct(Product("Tekken 10",           "Video Games",        42.95,   0, "There is no description"));
    addProduct(Product("Tekken 11",           "Video Games",        58.95,   1, "There is no description"));
}

string readProduct(fstream &file)
{
    short fieldSize; char *text = nullptr;
    file.read((char*)&fieldSize,sizeof(short));
    text=new char[fieldSize+1];
    file.read(text, fieldSize);
    text[fieldSize]='\0';
    string productText=text;
    delete[] text;
    return productText;
}

template<typename type>
type readProductNumber(fstream &file)
{
    type item;
    file.read((char*)&item,sizeof(type));
    return item;
}

bool Products::initializingData()
{
    fstream file("products.dat", ios::binary| ios::in);
    if(!file.is_open())
        return false;

    int length=0;
    file.read((char*)&length,sizeof(int));
    for(int i=0 ; i<length ; i++)
    {
        Product product(readProductNumber<int>(file));
        product.setName(readProduct(file));
        product.setCategoryName(readProduct(file));
        product.setPrice(readProductNumber<double>(file));
        product.setQuantity(readProductNumber<int>(file));
        product.setDescription(readProduct(file));

        addProduct(product);
    }
    file.close();
    return true;
}

void writeProduct(fstream &file,const string& sellerText)
{
    short fieldSize;
    fieldSize=sellerText.size();
    file.write((char*)&fieldSize,sizeof(short));
    file.write(sellerText.c_str(),fieldSize);
}

template<typename type>
void writeProduct(fstream &file,type number)
{
    file.write((char*)&number,sizeof(type));
}

bool Products::saveData()
{
    fstream file("products.dat",ios::out | ios::binary | ios::trunc);
    if (!file.is_open())
        return false;

    int length=productsLength();
    file.write((char*) (&length),sizeof(int));
    for(int i=0 ; i<length ; i++)
    {
        Product product=getCopyProductAt(i);

        writeProduct(file,product.getId());
        writeProduct(file,product.getName());
        writeProduct(file,product.getCategoryName());
        writeProduct(file,product.getPrice());
        writeProduct(file,product.getQuantity());
        writeProduct(file,product.getDescription());
    }
    file.close();
    return true;
}

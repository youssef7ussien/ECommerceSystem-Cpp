#include "seller.h"

int Seller::count=0;
Seller::Seller() : Account()
{}

//Seller::Seller(string firstName, string lastName, string userName, string email, string password,
//        Products products, Categories category) : Account(firstName,lastName,userName,email,password)
//{
//    id=count++;
//    this->products=products;
//    this->categories=category;
//}

Seller::Seller(string firstName, string lastName, string userName, string email, string password,Products products)
    : Account(firstName,lastName,userName,email,password)
{
    id=count++;
    this->products=products;
}

int Seller::getId() const
{
    return id;
}

Products Seller::getProducts() const
{
    return products;
}

Product* Seller::getProduct(int index)
{
    return products[index];
}

Categories Seller::getCategories() const
{
    return categories;
}

bool Seller::addProduct(Product item)
{
    products.addProduct(item);
    return true;
}
//
//bool Seller::updateItemName(int Id,string newName)
//{
//    products->updateName(Id,newName);
//    return true;
//}
//bool Seller::updateItemDescription(int Id,string newDescription)
//{
//    products->updateDescription(Id,newDescription);
//    return true;
//}
//
//bool Seller::updateItemPrice(int Id,int newPrice)
//{
//    products->updatePrice(Id,newPrice);
//    return true;
//}
//
//bool Seller::addCategory(Category Category1)
//{
//    categories.addCategory(Category1);
//    return true;
//}
//
//bool Seller::removeCategory(string name)
//{
//    categories.removeCategory(name);
//    return true;
//}
//
//bool Seller::addItemToCategory(string name,int itemId)
//{
//    categories.getCategory(name)->addItem(itemId);
//    return true;
//}
//
//bool Seller::removeItemFromCategory(string name,int itemId)
//{
//    categories.getCategory(name)->deleteItem(itemId);
//    return true;
//}
//


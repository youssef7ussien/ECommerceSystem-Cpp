#include "seller.h"

int Seller::count=0;
Seller::Seller() : Account()
{}

Seller::Seller(string firstName, string lastName, string userName, string email, string password)
        : Account(firstName,lastName,userName,email,password)
{
    id=count++;
}

Seller::Seller(string firstName, string lastName, string userName, string email, string password,
        List<int> productsId) : Account(firstName,lastName,userName,email,password)
{
    id=count++;
    this->productsId=productsId;
}

int Seller::getId() const
{
    return id;
}

int Seller::numberProducts() const
{
    return productsId.getLength();
}

bool Seller::addProduct(int productId)
{
    productsId.insertLast(productId);
    return true;
}

bool Seller::deleteProduct(int id)
{
    return productsId.remove<int>(id);
}

int Seller::deleteProductAt(int index)
{
    int id=*productsId[index];
    productsId.removeAt(index);
    return id;
}

int Seller::getProductId(int index) const
{
    return productsId.getCopyItem(index);
}

void Seller::getProducts(Product *product[],List<Product> products)
{
    for(int i=0 ; i<productsId.getLength() ; i++)
        product[i]=products.getItem(productsId.getCopyItem(i));
}

bool Seller::operator ==(string username) const
{
    return (this->userName==username);
}

bool Seller::operator !=(string username) const
{
    return (this->userName!=username);
}

bool Seller::operator ==(int id) const
{
    return (this->id==id);
}

bool Seller::operator !=(int id) const
{
    return (this->id!=id);
}
#include "seller.h"

int Seller::count=0;

Seller::Seller() : Account()
{}

Seller::Seller(int id) : Account()
{
    this->id=id;
    count++;
}

//Seller::Seller(const Account &account) : Account(account.getFirstName(),account.getLastName()
//                                            ,account.getUserName(),account.getEmail(),
//                                            account.getEmail()
//                                         )
//{
//    id=count++;
//}

Seller::Seller(const string& firstName, const string& lastName, const string& userName,
        const string& email, const string& password): Account(firstName,lastName,userName,email,password)
{
    id=count++;
}

Seller::Seller(const string& firstName, const string& lastName, const string& userName,
        const string& email, const string& password,List<int> productsId)
        : Account(firstName,lastName,userName,email,password)
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

void Seller::addProductId(int productId)
{
    productsId.insertLast(productId);
}

bool Seller::deleteProductId(int id)
{
    return productsId.remove<int>(id);
}

int Seller::deleteProductIdAt(int index)
{
    int productId;
    productsId.removeAt(index,productId);
    return productId;
}

int Seller::getProductId(int index) const
{
    return productsId.getCopyItemAt(index);
}

void Seller::getProducts(Product *product[],List<Product> products)
{
    for(int i=0 ; i<productsId.getLength() ; i++)
        product[i]=products.getItem(productsId.getCopyItemAt(i));
}

bool Seller::operator ==(const string& email) const
{
    return (this->email==email);
}

bool Seller::operator !=(const string& email) const
{
    return (this->email!=email);
}

bool Seller::operator ==(int id) const
{
    return (this->id==id);
}

bool Seller::operator !=(int id) const
{
    return (this->id!=id);
}

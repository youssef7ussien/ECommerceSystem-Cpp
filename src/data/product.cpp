#include "product.h"

int Product::count=0;

Product::Product()
{
    this->name = "";
    this->categoryName = "";
    this->price = 0.0;
    this->description = "";
    this->id=-1;
}

Product::Product(string name, string categoryName , double price, string description)
{
    this->name=name;
    this->categoryName=categoryName;
    this->price=price;
    this->description=description;
    id=count++;
}

bool Product::operator ==(Product product) const
{
    return (product.name == name && product.categoryName == categoryName &&
            product.price == price && product.description == description && product.id == id);
}

bool Product::operator !=(Product product) const
{
    return (product.name != name && product.categoryName != categoryName &&
            product.price != price && product.description != description && product.id != id);
}

bool Product::operator ==(int id) const
{
    return ( this->id == id);
}

bool Product::operator !=(int id) const
{
    return (this->id != id);
}

bool Product::operator ==(string name) const
{
    return (this->name == name);
}

bool Product::operator !=(string name) const
{
    return (this->name != name);
}

int Product::getId() const
{
    return id;
}

int Product::generateId()
{
     id=count++;
     return id;
}

string Product::getName() const
{
    return name;
}

string Product::getCategoryName() const
{
    return categoryName;
}

double Product::getPrice() const
{
    return price;
}

string Product::getDescription() const
{
    return description;
}

void Product::setName(string newName)
{
    name = newName;
}

void Product::setCategoryName(string categoryName)
{
    this->categoryName = categoryName;
}

void Product::setPrice(double price2)
{
    this->price = price2;
}

void Product::setDescription(string description)
{
    this->description = description;
}

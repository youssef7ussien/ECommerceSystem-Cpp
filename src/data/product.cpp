#include "product.h"

int Product::count=0;

Product::Product()
{
    this->name="";
    this->categoryName="";
    this->price=0.0;
    this->quantity=0;
    this->description="";
    this->id=-1;
}

Product::Product(string name,string categoryName,double price,string description)
{
    this->name=name;
    this->categoryName=categoryName;
    this->price=price;
    this->quantity=0;
    this->description=description;
    id=count++;
}

Product::Product(string name,string categoryName,double price,int quantity,string description)
{
    this->name=name;
    this->categoryName=categoryName;
    this->price=price;
    this->quantity=quantity;
    this->description=description;
    id=count++;
}

Product::Product(int id,string name,string categoryName,double price,int quantity,string description)
{
    this->name=name;
    this->categoryName=categoryName;
    this->price=price;
    this->quantity=quantity;
    this->description=description;
    this->id=id;
}

bool Product::operator ==(Product product) const
{
    return (product.name==name && product.categoryName==categoryName &&
            product.price==price && product.description==description && product.id==id);
}

bool Product::operator !=(Product product) const
{
    return (product.name!=name && product.categoryName!=categoryName &&
            product.price!=price && product.description!=description && product.id!=id);
}

bool Product::operator ==(int id) const
{
    return ( this->id==id);
}

bool Product::operator !=(int id) const
{
    return (this->id!=id);
}

bool Product::operator ==(string subName) const
{
    return name.find(subName)==std::string::npos ? false : true;
}

bool Product::outOfStock() const
{
     return quantity==0;
}

bool Product::decreaseStock()
{
    if(outOfStock())
        return false;
    quantity--;
    return true;
}

void Product::increaseStock()
{
    quantity++;
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

void Product::setName(string newName)
{
    name = newName;
}

string Product::getName() const
{
    return name;
}

void Product::setCategoryName(string categoryName)
{
    this->categoryName=categoryName;
}

string Product::getCategoryName() const
{
    return categoryName;
}

void Product::setPrice(double price)
{
    this->price=price;
}

double Product::getPrice() const
{
    return price;
}
void Product::setQuantity(int quantity)
{
    this->quantity=quantity;
}

int Product::getQuantity() const
{
    return quantity;
}
string Product::getDescription() const
{
    return description;
}

void Product::setDescription(string description)
{
    this->description=description;
}

//char toLowerCase(char c)
//{
//    return (c>=97 ? c : c+32);
//}

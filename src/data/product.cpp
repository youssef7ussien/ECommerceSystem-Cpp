#include "product.h"

int Product::count=0;

Product::Product()
{
    this->id=-1;
    this->name="";
    this->categoryName="";
    this->price=0.0;
    this->quantity=0;
    this->description="";
}

Product::Product(int id)
{
    this->id=id;
    count++;
    this->name="";
    this->categoryName="";
    this->price=0.0;
    this->quantity=0;
    this->description="";
}

Product::Product(string name,string categoryName,double price,int quantity,string description)
{
    id=count++;
    this->name=name;
    this->categoryName=categoryName;
    this->price=price;
    this->quantity=quantity;
    this->description=description;
}

Product::Product(int id,string name,string categoryName,double price,int quantity,string description)
{
    this->id=id;
    count++;
    this->name=name;
    this->categoryName=categoryName;
    this->price=price;
    this->quantity=quantity;
    this->description=description;
}

bool Product::operator ==(const Product& product) const
{
    return (product.name==name && product.categoryName==categoryName &&
            product.price==price && product.description==description && product.id==id);
}

bool Product::operator !=(const Product& product) const
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

bool Product::operator ==(const string &subName) const
{
    return name.find(subName)!=std::string::npos;
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
    name=newName;
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

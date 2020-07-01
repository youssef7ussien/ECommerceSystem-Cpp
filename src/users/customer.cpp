#include "customer.h"
#include <ctime>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

PurchaseData::PurchaseData()
{
    name=address=phoneNumber=email=country="";
}

string PurchaseData::getName() const
{
    return name;
}

void PurchaseData::setName(string name)
{
    this->name=name;
}

string PurchaseData::getAddress() const
{
    return address;
}

void PurchaseData::setAddress(string address)
{
    this->address=address;
}

string PurchaseData::getEmail() const
{
    return email;
}

void PurchaseData::setEmail(string email)
{
    this->email=email;
}

string PurchaseData::getPhoneNumber() const
{
    return phoneNumber;
}

void PurchaseData::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber=phoneNumber;
}

string PurchaseData::getCountry() const
{
    return country;
}

void PurchaseData::setCountry(string country)
{
    this->country=country;
}

double PurchaseData::shippingExpenses(double price) const
{
    return 0.05*price;
}

double PurchaseData::totalPrice(double price) const
{
    return price+shippingExpenses(price);
}

string PurchaseData::getDate()
{
    time_t now=time(0);
    string date=ctime(&now);
    /* date(0,2)    = date.substr(0,3)   -> day name
     * date(4,6)    = date.substr(4,3)   -> month
     * date(8,9)    = date.substr(8,2)   -> day number
     * date(11,18)  = date.substr(11,8)  -> clock
     * date(20,23)  = date.substr(20,4)  -> year
     */
    return date.substr(0,3)+", "+date.substr(8,2)+" "+date.substr(4,3)
           +" "+date.substr(20,4)+", at "+date.substr(11,8);
}

// **********************************************************************************

Customer::Customer()
{
    name="";
}

Customer::Customer(string name)
{
    this->name=name;
}

string Customer::getName() const
{
    return name;
}

int Customer::cartLength() const
{
    return cart.getLength();
}

Queue<Product> Customer::getCart() const
{
    return cart;
}

void Customer::clearCart()
{
    cart.clear();
}

PurchaseData Customer::getPurchaseData() const
{
    return this->PD;
}

void Customer::createPurchaseData(PurchaseData PD)
{
    this->PD=PD;
}

void Customer::addToCart(const Product& product)
{
    cart.enqueue(product);
}

Product Customer::removeFromCart()
{
    return cart.dequeue();
}

string createFileName(const string& fileName)
{
    string newName=fileName+"-invoice.txt";
    ifstream file(newName);
    for(int i=1 ; i>0 ; i++)
    {
        if(file)
        {
            file.close();
            newName=fileName+" - invoice ("+to_string(i)+").txt";
            file.open(newName);
        }
        else
        {
            file.close();
            return newName;
        }
    }
    return newName;
}

void line(ofstream &invoiceFile,int length)
{
    while(length--)
        invoiceFile<<"-";
    invoiceFile<<endl;
}

void Customer::printPurchaseData(Queue<Product> products)
{
    ofstream invoiceFile(createFileName(PD.getName()));

    if(!invoiceFile.is_open())
    {
        return;
    }

    line(invoiceFile,90);
    invoiceFile<<"Order Date : "<<PD.getDate()<<endl;
    line(invoiceFile,90);

    invoiceFile<<endl<<"Customer Information : "<<endl;
    invoiceFile<<"\t"; line(invoiceFile,70);
    invoiceFile<<"\t "<<setw(20)<<left<<"* Name"<<setw(40)<<left<<PD.getName()<<endl;
    invoiceFile<<"\t"; line(invoiceFile,70);
    invoiceFile<<"\t "<<setw(20)<<left<<"* Phone Number"<<setw(40)<<left<<PD.getPhoneNumber()<<endl;
    invoiceFile<<"\t"; line(invoiceFile,70);
    invoiceFile<<"\t "<<setw(20)<<left<<"* Email"<<setw(40)<<left<<PD.getEmail()<<endl;
    invoiceFile<<"\t"; line(invoiceFile,70);
    invoiceFile<<"\t "<<setw(20)<<left<<"* Country"<<setw(40)<<left<<PD.getCountry()<<endl;
    invoiceFile<<"\t"; line(invoiceFile,70);
    invoiceFile<<"\t "<<setw(20)<<left<<"* Address"<<setw(40)<<left<<PD.getAddress()<<endl;
    invoiceFile<<"\t"; line(invoiceFile,70);

    line(invoiceFile,90);
    invoiceFile<<"\nProducts :"<<endl;

    invoiceFile<<"     "; line(invoiceFile,79);
    invoiceFile<<"\t";
    invoiceFile<<setw(10)<<left<<"Number";
    invoiceFile<<setw(33)<<left<<"Name";
    invoiceFile<<setw(18)<<left<<"Category";
    invoiceFile<<setw(13)<<left<<"price";
    invoiceFile<<endl;
    invoiceFile<<"     "; line(invoiceFile,79);

    double price=0.0;
    for(int i=0; products.getLength() ; i++)
    {
        Product product=products.dequeue();
        invoiceFile<<"\t";
        invoiceFile<<left;
        invoiceFile<<setw(7)<<i+1<<"   ";
        invoiceFile<<setw(30)<<product.getName()<<"   ";
        invoiceFile<<setw(15)<<product.getCategoryName()<<"   ";
        invoiceFile<<setw(10)<<right<<product.getPrice()<<" $"<<endl;

        price+=product.getPrice();
    }

    invoiceFile<<"     "; line(invoiceFile,79);

    invoiceFile<<"\tshippingExpenses : "<<setw(52)<<right<<PD.shippingExpenses(price)<<" $"<<endl;
    invoiceFile<<"     "; line(invoiceFile,79);

    invoiceFile<<"\tTotal Price : "<<setw(57)<<right<<PD.totalPrice(price)<<" $"<<endl;
    invoiceFile<<"     "; line(invoiceFile,79);

    line(invoiceFile,90);
    invoiceFile.close();
}

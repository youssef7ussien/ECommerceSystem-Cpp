#include "sellers.h"
#include <fstream>
#include <cstring>

Sellers::Sellers()
{}

void Sellers::addSeller(Seller seller)
{
   sellers.insertLast(seller);
}

int Sellers::getLength() const
{
   return sellers.getLength();
}

int Sellers::requestLength() const
{
   return waitingList.getLength();
}

Queue<Seller> Sellers::getRequests() const
{
    return waitingList;
}

Seller* Sellers::getSeller(int id)
{
    return sellers.getItem(id);
}

Seller* Sellers::getSellerAt(int index)
{
    return sellers[index];
}

Seller Sellers::getCopySellerAt(int index) const
{
   return sellers.getCopyItemAt(index);
}

Seller Sellers::firstRequest() const
{
   return waitingList.getFront();
}

void Sellers::addSeller()
{

   sellers.insertLast(waitingList.dequeue());
}

void Sellers::addRequest(const Seller &seller)
{
   waitingList.enqueue(seller);
}

void Sellers::removeRequest()
{
   waitingList.dequeue();
}

void Sellers::deleteSellerAt(int index)
{
   sellers.removeAt(index);
}

void Sellers::deleteSellerAt(int index,Seller &seller)
{
   sellers.removeAt(index,seller);
}

bool Sellers::checkSeller(const string& email,const string& password,int &id) const
{
    Seller seller;
    if(sellers.contain<string>(email,seller))
    {
        if(seller.getEmail()==email && seller.getPassword()==password)
        {
            id=seller.getId();
            return true;
        }
    }
    return false;
}

void Sellers::defaultData()  // For Test
{
    Seller seller1("Youssef","Hussien","seller01","seller01@commerce.com","01010101");
    seller1.addProductId(0);
    seller1.addProductId(3);
    seller1.addProductId(4);
    seller1.addProductId(6);
    seller1.addProductId(9);
    seller1.addProductId(16);
    seller1.addProductId(18);
    seller1.addProductId(19);
    seller1.addProductId(20);
    addRequest(seller1);
    addSeller();

    Seller seller2("Hossam","Mahmoud","seller02","seller02@commerce.com","02020202");
    seller2.addProductId(1);
    seller2.addProductId(5);
    seller2.addProductId(10);
    seller2.addProductId(11);
    seller2.addProductId(14);
    seller2.addProductId(17);
    addRequest(seller2);
    addSeller();

    Seller seller3("Abdelrahman","Salem","seller03","seller03@commerce.com","03030303");
    seller3.addProductId(2);
    seller3.addProductId(7);
    seller3.addProductId(8);
    seller3.addProductId(12);
    seller3.addProductId(13);
    seller3.addProductId(15);
    addRequest(seller3);
    addSeller();

    Seller seller4("Ahmed","Nady","seller04","seller04@commerce.com","04040404");
    addRequest(seller4);
    Seller seller5("Mahmoud","Soliman","seller05","seller05@commerce.com","05050505");
    addRequest(seller5);
}

string readSeller(fstream &file)
{
    short fieldSize; char *text = nullptr;
    file.read((char*)&fieldSize,sizeof(short));
    text=new char[fieldSize+1];
    file.read(text, fieldSize);
    text[fieldSize]='\0';
    string sellerText=text;
    delete[] text;

    return sellerText;
}

int readSellerInt(fstream &file)
{
    int number;
    file.read((char*)&number,sizeof(int));
    return number;
}

bool Sellers::initializingData()
{
    fstream file("sellers.dat", ios::binary| ios::in);
    if(!file.is_open())
        return false;

    int length=readSellerInt(file);
    for(int i=0 ; i<length ; i++)
    {
        Seller seller(readSellerInt(file));

        seller.setFirstName(readSeller(file));
        seller.setLastName(readSeller(file));
        seller.setUserName(readSeller(file));
        seller.setEmail(readSeller(file));
        seller.setPassword(readSeller(file));

        int numProduct=readSellerInt(file);
        for(int j=0 ; j<numProduct ; j++)
            seller.addProductId(readSellerInt(file));

        addSeller(seller);
    }

    length=readSellerInt(file);
    for(int i=0 ; i<length ; i++)
    {
        Seller seller(readSellerInt(file));

        seller.setFirstName(readSeller(file));
        seller.setLastName(readSeller(file));
        seller.setUserName(readSeller(file));
        seller.setEmail(readSeller(file));
        seller.setPassword(readSeller(file));

        addRequest(seller);
    }

    file.close();
    return true;
}

void writeSeller(fstream &file,const string& sellerText)
{
    short fieldSize;
    fieldSize=sellerText.size();
    file.write((char*)&fieldSize,sizeof(short));
    file.write(sellerText.c_str(),fieldSize);
}

void writeSeller(fstream &file,int number)
{
    file.write((char*)&number,sizeof(int));
}

bool Sellers::saveData()
{
    fstream file("sellers.dat",ios::out | ios::binary | ios::trunc);
    if (!file.is_open())
        return false;

    int length=getLength();
    file.write((char*)&length,sizeof(int));
    for(int i=0 ; i<length ; i++)
    {
        Seller seller=getCopySellerAt(i);

        writeSeller(file,seller.getId());
        writeSeller(file,seller.getFirstName());
        writeSeller(file,seller.getLastName());
        writeSeller(file,seller.getUserName());
        writeSeller(file,seller.getEmail());
        writeSeller(file,seller.getPassword());

        writeSeller(file,seller.numberProducts());
        for(int j=0 ; j<seller.numberProducts() ; j++)
            writeSeller(file,seller.getProductId(j));
    }

    length=requestLength();
    file.write((char*)&length,sizeof(int));

    if(length==0)
    {
        file.close();
        return true;
    }

    Queue<Seller> requestTemp=waitingList.copy();
    for(int i=0 ; i<length ; i++)
    {
        Seller seller=requestTemp.dequeue();
        writeSeller(file,seller.getId());
        writeSeller(file,seller.getFirstName());
        writeSeller(file,seller.getLastName());
        writeSeller(file,seller.getUserName());
        writeSeller(file,seller.getEmail());
        writeSeller(file,seller.getPassword());
    }

    file.close();
    return true;
}

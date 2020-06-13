#include <iostream>
#include <regex>
#include "Graphics.h"
#include "seller_interface.h"
#include "../data/product.h"

using namespace std;

void productSellerBoxInfo(int x,int y,int number,const Product product)
{
    drawRectangle(x,y,44,1);
    setCursor(x+5,y); cout<<char(194);
    setCursor(x+2,y+1); cout<<number;
    setCursor(x+5,y+1); cout<<char(179);
    setCursor(x+5,y+2); cout<<char(193);
    setCursor(x+7,y+1); cout<<product.getName();
    setCursor(x+31,y); cout<<char(194);
    setCursor(x+31,y+1); cout<<char(179);
    setCursor(x+31,y+2); cout<<char(193);
    setCursor(x+33,y+1); cout<<product.getPrice()<<" $";
}

void productSellerButton(int x,int y,int numberProduct)
{
    for(int i=0 ; i<numberProduct ; i++)
    {
        drawRectangle(x,y,32,1);
        setCursor(x+11,y); cout<<char(194);
        setCursor(x+11,y+1); cout<<char(179);
        setCursor(x+11,y+2); cout<<char(193);

        setCursor(x+22,y); cout<<char(194);
        setCursor(x+22,y+1); cout<<char(179);
        setCursor(x+22,y+2); cout<<char(193);
        y+=3;
    }
}

void productSellerButtonName(int x,int y,int numberProduct,int index)
{
    string buttons[]={"  Show  ","  Edit  "," Delete "};
    for(int i=0 ; i<numberProduct*3 ; i++)
    {
        index==i ? color(BLACK,RED) : color();
        setCursor(x+10*(i%3)+i%3,3*(i/3)+y+1); cout<<buttons[i%3];
    }
    color();
}

int firstPageOfSeller(const Seller &seller,Product *products[])
{
    int numberProducts=seller.numberProducts(), remainingProducts=0, page=1, length=0;
    bool nextPage=false, prevPage=false;
    if(numberProducts>8) // 8 -> The number of products per page
        { remainingProducts=numberProducts-8; length=8; }
    else
        { remainingProducts=0; length=numberProducts; }

    while(1)
    {
        system("cls");
        char key='0'; int index=0;
        drawRectangle(6,1,117,1,2); // Status Bar
        setCursor(8,2); cout<<"Hello, "; color(RED); cout<<seller.getFirstName();
        setCursor(104,2); color(DARK_GRAY); cout<<"Press ";
        color(BROWN); cout<<"Esc"; color(DARK_GRAY); cout<<" to Logout"; color();
        drawRectangle(13,4,20,1); // Option add Product Box
        drawLine(36,5,36,20);
        if(nextPage)
        {
            if(remainingProducts/8)
                { length=8; remainingProducts-=8; }
            else
                { length=remainingProducts; remainingProducts=0; }
            nextPage=false; page++;
        }
        else if(prevPage)
        {
            remainingProducts+=(length-2)/3;
            length=8;
            prevPage=false; page--;
        }

        for(int i=numberProducts-(remainingProducts+length),y=4 ; i<numberProducts-remainingProducts ; i++, y+=3) // Products information
            productSellerBoxInfo(38,y,i+1,*products[i]);
        productSellerButton(84,4,length); // Products buttons options
        setCursor(64,30); cout<<page; // page number
        length=length*3+3; // *3 -> number of buttons in per row || +3 -> next , previous , add product
        while(key!=KEY_ENTER)
        {
            productSellerButtonName(86,4,(length-3)/3,index); // *3 -> number of buttons in per row || +3 -> next , previous , add product
            if(index==length-2)
                remainingProducts+12<numberProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(59,30); cout<<" < "; color();
            if(index==length-1)
                remainingProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(67,30); cout<<" > "; color();

            if(index==length-3)
                color(BLACK,RED);
            setCursor(15,5); cout<<"   Add Product   "; color(); // Option add Product Box
            while(1)
            {
                key=getch();
                if(key==KEY_RIGHT)
                    { index=(index+1)%length; break; }
                else if(key==KEY_LEFT)
                    { index=(index+length-1)%length; break; }
                else if(key==KEY_DOWN)
                {
                    index+3<length-2 ? index+=3 : index=length-3; // 3 -> number of buttons in per row
                    break;
                }
                else if(key==KEY_UP)
                {
                    index-3>=0 ? index-=3 : index=length-3; // 3 -> number of buttons in per row
                    break;
                }
                else if(key==KEY_ENTER)
                {
                    if(index==length-1 && remainingProducts)
                        { nextPage=true; break; }
                    else if(index==length-2 && remainingProducts+8<numberProducts)
                        { prevPage=true; break; }
                    else if(index==length-3)
                        return -1;
                    else if(index<length-3)
                        return (index+24*(page-1)); // 24 -> number of buttons options
                }
                else if(key==KEY_ESC) // for back
                    return -2;
            }
        }
    }
}

inline string inputText(string text)
{
    editCursor(true);
    char character=getchar();
    while(1)
    {
        if(character=='\n')
        {
            editCursor(false);
            return text;
        }
        text+=character;
        character=getchar();
    }
}

inline void initialBox(int x,int y,int width,int lengthLine,int height=1)
{
    setCursor(x+2,y+1);
    clearLine(lengthLine);
    color(RED); drawRectangle(x,y,width,height); color();
    setCursor(x+2,y+1);
}

bool validationInput(string name,string categoryName,string description,string price)
{
    bool validation=true;
    regex pattern("^[0-9]+([.][0-9]+)?$");
    if(name=="")
    {
        validation=false;
        setCursor(89,7); color(DARK_RED);
        cout<<"Incorrect name";
        color();
    }
    if(categoryName=="")
    {
        validation=false;
        setCursor(89,15); color(DARK_RED);
        cout<<"Incorrect category";
    }
    if(description=="")
    {
        validation=false;
        setCursor(102,24); color(DARK_RED);
        cout<<"Incorrect description";
    }
    if(!regex_match(price, pattern))
    {
        validation=false;
        setCursor(89,11); color(DARK_RED);
        cout<<"Incorrect price";
    }
    color();
    return validation;
}

bool interfaceAddProduct(Product &product)
{
    system("cls");
    char key='0';  int index=2;
    drawRectangle(50,1,30,1,2); // login box
    setCursor(64,2); cout<<"Add new Product";
    drawRectangle(44,6,42,1); // Name box
    setCursor(45,5); cout<<"Name";
    drawRectangle(44,10,42,1); // Price box
    setCursor(45,9); cout<<"Price";
    drawRectangle(44,14,42,1); // Category box
    setCursor(45,13); cout<<"Category";
    drawRectangle(6,18,117,4); // Description box
    setCursor(6,17); cout<<"Description";
    drawRectangle(50,25,14,1); // Again box
    drawRectangle(66,25,14,1); // Exit box
    string price;
    while(key!=KEY_ENTER)
    {
        setCursor(52,26);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,26);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            initialBox(44,6,42,product.getName().size());
            product.setName("");
            product.setName(inputText(product.getName()));
            drawRectangle(44,6,42,1);

            initialBox(44,10,42,price.size());
            price="";
            price=inputText(price);
            drawRectangle(44,10,42,1);

            initialBox(44,14,42,product.getCategoryName().size());
            product.setCategoryName("");
            product.setCategoryName(inputText(product.getCategoryName()));
            drawRectangle(44,14,42,1);


            initialBox(6,18,117,product.getDescription().size(),4);
            product.setDescription("");
            product.setDescription(inputText(product.getDescription()));

            if(validationInput(product.getName(),product.getCategoryName(),product.getDescription(),price))
            {
                product.setPrice(atof(price.c_str()));
                return true;
            }
            drawRectangle(6,18,117,4);
            index=0;
            continue;
        }
        while(1)
        {
            key=getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_LEFT)
                { index=(index+3)%2; break; }
            else if(key==KEY_ENTER)
                break;
        }
        if(key==KEY_ENTER && index==0)
        {
            key='0';
            index=2;
            setCursor(89,7);   cout<<"                       ";
            setCursor(89,11);  cout<<"                       ";
            setCursor(89,15);  cout<<"                       ";
            setCursor(102,24); cout<<"                       ";
        }
    }
    return false;
}

string editField(int x,int y,string text,int width,int height,bool isPrice=false)
{
    setCursor(89,y+1); cout<<"               ";
    initialBox(x,y,width,text.size(),height);
    if(height==4)
        y-=2;
    while(1)
    {
        text="";
        text=inputText(text);
        if(text=="")
        {
            setCursor(89,y+1); cout<<"               "; wait(200);
            setCursor(89,y+1); color(DARK_RED);
            cout<<"Incorrect input";
            setCursor(x+2,height==4 ? y+3 : y+1);
            color();
        }
        else
        {
            if(isPrice)
            {
                regex pattern("^[0-9]+([.][0-9]+)?$");
                if(!regex_match(text, pattern))
                {
                    setCursor(89,y+1); cout<<"               "; wait(200);
                    setCursor(89,y+1); color(DARK_RED);
                    cout<<"Incorrect price";
                    setCursor(x+2,y+1);
                    clearLine(text.size());
                    setCursor(x+2,y+1);
                    color();
                    continue;
                }
            }
            setCursor(89,y+1); cout<<"               ";
            color(GREEN); drawRectangle(x, height==4 ? y+2 : y ,width,height);
            setCursor(89,y+1); cout<<"Done";
            color();
            return text;
        }
    }
}

bool interfaceEditProduct(Product *product)
{
    system("cls");
    char key='0';  int index=0;
    drawRectangle(50,1,30,1,2); // login box
    setCursor(58,2); cout<<"Add new Product";
    drawRectangle(44,6,42,1); // Name box
    setCursor(45,5); cout<<"Name";
    setCursor(46,7); color(DARK_GRAY); cout<<product->getName(); color();
    drawRectangle(44,10,42,1); // Price box
    setCursor(45,9); cout<<"Price";
    setCursor(46,11); color(DARK_GRAY); cout<<product->getPrice(); color();
    drawRectangle(44,14,42,1); // Category box
    setCursor(45,13); cout<<"Category";
    setCursor(46,15); color(DARK_GRAY); cout<<product->getCategoryName(); color();
    drawRectangle(5,18,117,4); // Description box
    setCursor(6,17); cout<<"Description";
    setCursor(7,19); color(DARK_GRAY); cout<<product->getDescription(); color();
    for(int i=0 ; i<3 ; i++)
        drawRectangle(33,4*i+6,8,1);
    drawRectangle(20,15,8,1);
    drawRectangle(54,25,22,1); // DONE box
    while(key!=KEY_ENTER)
    {
        if(index==6) // Name
        {
            product->setName(editField(44,6,product->getName(),42,1));
            index=1;
        }
        else if(index==7) // Price
        {
            string price=to_string(product->getPrice());
            price=editField(44,10,price,42,1,true);

            product->setPrice(atof(price.c_str()));
            index=2;
        }
        else if(index==8) // Category
        {
            product->setCategoryName(editField(44,14,product->getCategoryName(),42,1));
            index=3;
        }
        else if(index==9) // Description
        {
            product->setDescription(editField(5,18,product->getDescription(),117,4));
            index=4;
        }

        setCursor(35,7);
        if(index==0)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(35,11);
        if(index==1)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(35,15);
        if(index==2)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(22,16);
        if(index==3)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(56,26);
        if(index==4)  color(BLACK,RED);
        cout<<"        DONE        "; color();

        while(1)
        {
            key=getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%5; break; }
            else if(key==KEY_LEFT)
                { index=(index+6)%5; break; }
            else if(key==KEY_DOWN)
                { index=(index+1)%5; break; }
            else if(key==KEY_UP)
                { index=(index+6)%5; break; }
            else if(key==KEY_ENTER)
            {
                key='0';
                if(index>=0 && index<=3)
                    { index+=6; break; }
                else if(index==4)
                    return true;
            }
            else if(key==KEY_ESC)
                return false;
        }
    }
    return false;
}

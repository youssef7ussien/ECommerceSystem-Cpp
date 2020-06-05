#include <iostream>
#include "seller_interface.h"
#include "product.h"
#include "Graphics.h"
#include <regex>

using namespace std;

void productSellerBoxInfo(int x,int y,const Product product)
{
    drawRectangle(x,y,44,1);
    setCursor(x+5,y); cout<<char(194);
    setCursor(x+2,y+1); cout<<product.getId();
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

int firstPageOfSeller(const Seller &seller)
{
    int numberProducts=seller.getProducts().getLength(), remainingProducts=0, page=1, length=0;
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

       // drawRectangle(55,29,5,1); // prevPage
       // drawRectangle(67,29,5,1); // nextPage
        for(int i=numberProducts-(remainingProducts+length),y=4 ; i<numberProducts-remainingProducts ; i++, y+=3) // Products information
            productSellerBoxInfo(38,y,seller.getProductConst(i));
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
            setCursor(15,5); cout<<"   Add Product   "; color(); // Option add Product Boxe
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

string inputText(string text)
{
    char character=getchar();
    while(1)
    {
        if(character=='\n')
        {
            return text;
            break;
        }
        text+=character;
        character=getchar();
    }
}


bool interfaceAddProduct()
{
    system("cls");
    char key=80;  int index=2;
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
    Product product;
    while(key!=13)
    {
        setCursor(52,26);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,26);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2) // Name
        {
            editCursor(true);
            setCursor(46,7);
            clearLine(product.getName().size());
            product.setName("");
            color(RED); drawRectangle(44,6,42,1); color();
            setCursor(46,7);
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=3;
                    break;
                }
                product.setName(product.getName()+character);
                character=getchar();
            }
            drawRectangle(44,6,42,1);
        }
        if(index==3) // Price
        {
            editCursor(true);
            setCursor(46,11);
            clearLine(price.size());
            price="";
            color(RED); drawRectangle(44,10,42,1); color();
            setCursor(46,11);
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=4;
                    break;
                }
                price+=character;
                character=getchar();
            }
            drawRectangle(44,10,42,1);
        }
        if(index==4) // Category
        {
            editCursor(true);
            setCursor(46,15);
            clearLine(product.getCategoryName().size());
            product.setCategoryName("");
            color(RED); drawRectangle(44,14,42,1);  color();
            setCursor(46,15);
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=5;
                    break;
                }
                product.setCategoryName(product.getCategoryName()+character);
                character=getchar();
            }
            drawRectangle(44,14,42,1);
        }
        if(index==5) // Description
        {
            setCursor(8,19);
            clearLine(product.getDescription().size());
            product.setDescription("");
            color(RED); drawRectangle(6,18,117,4); color();
            setCursor(8,19);
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=0;
                    break;
                }
                product.setDescription(product.getDescription()+character);
                character=getchar();
            }
            editCursor(false);
            regex pattern("^[0-9]+([.][0-9]+)?$");
            if(!regex_match(price, pattern))
            {
                setCursor(89,11); color(DARK_RED);
                cout<<"Incorrect price";
                color();
            }
            else
            {
                product.setPrice(atof(price.c_str()));
//                productDetails(15,1,product);
                system("pause");
                return true;
            }
            drawRectangle(6,18,117,4);
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
            setCursor(89,15); cout<<"                       ";
        }
    }
    return false;
}

bool interfaceEditProduct(Product *product)
{
    system("cls");
    char key=80;  int index=2;
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
    Product tempProduct;
    while(key!=13)
    {
        setCursor(52,26);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,26);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2) // Name
        {
            editCursor(true);
            setCursor(46,7);
            clearLine(tempProduct.getName().size());
            tempProduct.setName("");
            color(RED); drawRectangle(44,6,42,1); color();
            setCursor(46,7);
            tempProduct.setName(inputText(tempProduct.getName()));
            index=3;
            drawRectangle(44,6,42,1);
        }
        if(index==3) // Price
        {
            setCursor(46,11);
            clearLine(price.size());
            price="";
            color(RED); drawRectangle(44,10,42,1); color();
            setCursor(46,11);
            price=inputText(price);
            index=4;
            drawRectangle(44,10,42,1);
        }
        if(index==4) // Category
        {
            setCursor(46,15);
            clearLine(tempProduct.getCategoryName().size());
            tempProduct.setCategoryName("");
            color(RED); drawRectangle(44,14,42,1);  color();
            setCursor(46,15);
            tempProduct.setCategoryName(inputText(tempProduct.getCategoryName()));
            index=5;
            drawRectangle(44,14,42,1);
        }
        if(index==5) // Description
        {
            setCursor(8,19);
            clearLine(tempProduct.getDescription().size());
            tempProduct.setDescription("");
            color(RED); drawRectangle(6,18,117,4); color();
            setCursor(8,19);
            tempProduct.setDescription(inputText(tempProduct.getDescription()));
            index=0;
            editCursor(false);
            regex pattern("^[0-9]+([.][0-9]+)?$");
            if(!regex_match(price, pattern))
            {
                setCursor(89,11); color(DARK_RED);
                cout<<"Incorrect price";
                color();
            }
            else
            {
                tempProduct.setPrice(atof(price.c_str()));
                product->setName(tempProduct.getName());
                product->setPrice(tempProduct.getPrice());
                product->setCategoryName(tempProduct.getCategoryName());
                product->setDescription(tempProduct.getDescription());
                return true;
            }
            drawRectangle(6,18,117,4);
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
            setCursor(89,15); cout<<"                       ";
        }
    }
    return false;
}

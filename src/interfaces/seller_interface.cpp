#include <iomanip>
#include "functions.h"
#include "seller_interface.h"
#include "graphics.h"

#define PRODUCT_NAME_PATTERN          "^[a-zA-z0-9 \\-,]{3,30}$"
#define PRODUCT_CATEGORY_PATTERN      "^[a-zA-z0-9 \\-]{3,15}$"
#define PRODUCT_PRICE_PATTERN         "^[0-9]{1,6}([.][0-9]{0,2})?$"
#define PRODUCT_DESCRIPTION_PATTERN   "^[a-zA-z0-9 ._()|,\\-]{3,120}$"
#define PRODUCT_QUANTITY_PATTERN      "^[0-9]{0,3}$"

void productButtonsName(int x,int y,int numberProduct,int index)
{
    string buttons[]={"  Show  ","  Edit  "," Delete "};
    for(int i=0 ; i<numberProduct*3 ; i++)
    {
        index==i ? color(BLACK,RED) : color();
        setCursor(x+10*(i%3)+i%3,3*(i/3)+y); cout<<buttons[i%3];
    }
    color();
}

void sellerInfo(const Seller &seller)
{
    setCursor(7,8); color(DARK_GRAY); cout<<"Name"; color();
    drawRectangle(6,9,32,1);
    setCursor(8,10); cout<<seller.getName();

    setCursor(7,13); color(DARK_GRAY); cout<<"Username"; color();
    drawRectangle(6,14,32,1);
    setCursor(8,15); cout<<seller.getUserName();

    drawRectangle(10,18,24,1);
    setCursor(12,19); color(DARK_GRAY); cout<<"Number of products "; color();
    cout<<setw(3)<<seller.numberProducts();

    drawLine(8,22,37,22,DARK_GRAY);
}

int keyboardControl(int page,int length,int remainingProducts,int numberProducts) // use in firstPageOfSeller()
{
    char key='0'; int index=0;
    while(key!=KEY_ENTER)
    {
        productButtonsName(92,8,(length-4)/3,index);

        if(index==length-4) color(BLACK,RED);
        setCursor(14,24); cout<<"     Profile      "; color();

        if(index==length-3) color(BLACK,RED);
        setCursor(14,27); cout<<"   Add Product    "; color();

        if(index==length-2)
            remainingProducts+8<numberProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
        setCursor(80,32); cout<<" < "; color();

        if(index==length-1)
            remainingProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
        setCursor(88,32); cout<<" > "; color();

        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
            {
                if(index==length-4 || index==length-3)
                    index=0;
                else
                    index=(index+1)%length;
                break;
            }
            else if(key==KEY_LEFT)
            {
                if(index%3==0 && index<length-4)
                    index=length-4;
                else
                    index=(index+length-1)%length;
                break;
            }
            else if(key==KEY_DOWN)
            {
                if(index==length-4 || index==length-3)
                    index+=1;
                else if(index==length-2 || index==length-1)
                    index=0;
                else
                    index+3<length-4 ? index+=3 : index=length-2;
                break;
            }
            else if(key==KEY_UP)
            {
                if(index==length-4 || index==length-3)
                    index-=1;
                else
                    index-3>=0 ? index-=3 : index=length-3;
                break;
            }
            else if(key==KEY_ENTER)
            {
                if(index==length-1 && remainingProducts)
                    return -5;
                else if(index==length-2 && remainingProducts+8<numberProducts)
                    return -4;
                else if(index==length-3)
                    return -3;
                else if(index==length-4)
                    return -2;
                else if(index<length-4)
                    return (index+24*(page-1)); // 24 -> number of buttons options
            }
            else if(key==KEY_ESC) // for back
                return -1;
            else if(key=='p')
                return -2;
            else if(key=='a')
                return -3;
            else if(key=='b' && remainingProducts+8<numberProducts)
                return -4;
            else if(key=='n' && remainingProducts)
                return -5;
        }
    }
    return -1;
}

int keyboardControl() // use in firstPageOfSeller()
{
    setCursor(70,20); cout<<"There are no products yet";
    char key='0'; int index=0;
    while(key!=KEY_ENTER)
    {
        if(index==0) color(BLACK,RED);
        setCursor(14,24); cout<<"     Profile      "; color();

        if(index==1) color(BLACK,RED);
        setCursor(14,27); cout<<"   Add Product    "; color();

        while(1)
        {
            key=_getch();
            if(key==KEY_DOWN || key==KEY_UP)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index==0 ? -2 : -3;
            else if(key==KEY_ESC) // for back
                return -1;
            else if(key=='p')
                return -2;
            else if(key=='a')
                return -3;
        }
    }
    return -1;
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
        statusBar(seller.getFirstName());
        setCursor(15,5); color(YELLOW); cout<<"Information"; color();
        drawLine(6,6,39,6,DARK_GRAY);
        setCursor(78,5); color(YELLOW); cout<<"Products"; color();
        drawLine(43,6,124,6,DARK_GRAY);
        sellerInfo(seller);
        drawRectangle(12,23,20,1); // Profile box
        drawRectangle(12,26,20,1); // Add product box
        drawLine(41,5,41,30,DARK_GRAY);

        if(seller.numberProducts()!=0)
        {
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
                remainingProducts+=length;
                length=8;
                prevPage=false; page--;
            }
            for(int i=numberProducts-(remainingProducts+length),y=7 ; i<numberProducts-remainingProducts ; i++, y+=3)
                productBox(44,y,i+1,*products[i],3);
            setCursor(85,32); cout<<page; // page number
            int result=keyboardControl(page,length*3+4,remainingProducts,numberProducts);
            if(result==-5)
                nextPage=true;
            else if(result==-4)
                prevPage=true;
            else
                return result;
        }
        else
            return keyboardControl();

    }
}

bool validationInput(const Product &product,string price,string quantity) // use in interfaceAddProduct()
{
    bool validation=true;
    if(product.getName()=="" || !validationRegex(PRODUCT_NAME_PATTERN,product.getName()))
    {
        validation=false;
        setCursor(89,7); color(DARK_RED);
        cout<<"Incorrect name";
        color();
    }
    if(product.getCategoryName()=="" || !validationRegex(PRODUCT_CATEGORY_PATTERN,product.getCategoryName()))
    {
        validation=false;
        setCursor(89,11); color(DARK_RED);
        cout<<"Incorrect category";
    }
    if(!validationRegex(PRODUCT_PRICE_PATTERN,price))
    {
        validation=false;
        setCursor(89,15); color(DARK_RED);
        cout<<"Incorrect price";
    }
    if(!validationRegex(PRODUCT_QUANTITY_PATTERN,quantity))
    {
        validation=false;
        setCursor(89,19); color(DARK_RED);
        cout<<"Incorrect quantity";
    }
    if(product.getDescription()=="" || !validationRegex(PRODUCT_DESCRIPTION_PATTERN,product.getDescription()))
    {
        validation=false;
        setCursor(102,28); color(DARK_RED);
        cout<<"Incorrect description";
    }
    color();
    return validation;
}

bool interfaceAddProduct(string sellerName,Product &product)
{
    system("cls");
    char key='0';  int index=2;
    statusBar(sellerName,"BACK");

    setCursor(45,5); cout<<"Name";
    drawRectangle(44,6,42,1); // Name box
    setCursor(45,9); cout<<"Category";
    drawRectangle(44,10,42,1); // Category box
    setCursor(45,13); cout<<"Price";
    drawRectangle(44,14,42,1); // Price box
    setCursor(45,17); cout<<"Quantity";
    drawRectangle(44,18,42,1); // Quantity box
    setCursor(6,21); cout<<"Description";
    drawRectangle(6,22,117,4); // Description box

    drawRectangle(50,29,14,1); // Again box
    drawRectangle(66,29,14,1); // Exit box

    string price="",quantity="";
    while(key!=KEY_ENTER)
    {
        setCursor(52,30);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,30);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            initialBox(44,6,42,product.getName().size());
            product.setName(inputText());
            drawRectangle(44,6,42,1);

            initialBox(44,10,42,product.getCategoryName().size());
            product.setCategoryName(inputText());
            drawRectangle(44,10,42,1);

            initialBox(44,14,42,price.size());
            price=inputText();
            drawRectangle(44,14,42,1);

            initialBox(44,18,42,quantity.size());
            quantity=inputText();
            drawRectangle(44,18,42,1);

            initialBox(6,22,117,product.getDescription().size(),4);
            product.setDescription(inputText());

            if(validationInput(product,price,quantity))
            {
                product.setPrice(atof(price.c_str()));
                product.setQuantity(atoi(quantity.c_str()));
                return true;
            }
            drawRectangle(6,22,117,4);
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

string editField(int x,int y,string text,string patternRegex,int width,int height=1) // use in interfaceEditProduct()
{
    setCursor(89,y+height); cout<<"               ";
    initialBox(x,y,width,text.size(),height);
    while(1)
    {
        text=inputText();
        if(text=="" || !validationRegex(patternRegex,text))
        {
            setCursor(x+2,y+1); clearLine(text.size());
            setCursor(89,y+height); cout<<"               "; wait(150);
            setCursor(89,y+height);
            color(DARK_RED); cout<<"Incorrect input";
            setCursor(x+2,y+1);
            color();
        }
        else
        {
            setCursor(89,y+height); cout<<"               ";
            color(GREEN); drawRectangle(x,y,width,height);
            setCursor(89,y+height); cout<<"Done";
            color();
            return text;
        }
    }
}

bool interfaceEditProduct(string sellerName,Product &product)
{
    system("cls");
    char key='0';  int index=0;
    statusBar(sellerName,"BACK");
    setCursor(45,5); cout<<"Name";
    drawRectangle(44,6,42,1); // Name box
    setCursor(46,7); color(DARK_GRAY); cout<<product.getName(); color();
    setCursor(45,9); cout<<"Category";
    drawRectangle(44,10,42,1); // Category box
    setCursor(46,11); color(DARK_GRAY); cout<<product.getCategoryName(); color();
    setCursor(45,13); cout<<"Price";
    drawRectangle(44,14,42,1); // Price box
    setCursor(46,15); color(DARK_GRAY); cout<<product.getPrice(); color();
    setCursor(6,17); cout<<"Description";
    drawRectangle(5,18,117,4); // Description box
    setCursor(7,19); color(DARK_GRAY); cout<<product.getDescription(); color();
    for(int i=0 ; i<3 ; i++)
        drawRectangle(33,4*i+6,8,1);
    drawRectangle(20,15,8,1);
    drawRectangle(54,25,22,1); // DONE box
    while(key!=KEY_ENTER)
    {
        if(index==6) // Name
        {
            product.setName(editField(44,6,product.getName(),PRODUCT_NAME_PATTERN,42));
            index=1;
        }
        else if(index==7) // Category
        {
            product.setCategoryName(editField(44,10,product.getCategoryName(),PRODUCT_CATEGORY_PATTERN,42));
            index=2;
        }
        else if(index==8) // Price
        {
            string price=to_string(product.getPrice());
            price=editField(44,14,price,PRODUCT_PRICE_PATTERN,42);

            product.setPrice(atof(price.c_str()));
            index=3;
        }
        else if(index==9) // Description
        {
            product.setDescription(editField(5,18,product.getDescription(),PRODUCT_DESCRIPTION_PATTERN,117,4));
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
            key=_getch();
            if(key==KEY_DOWN)
                { index=(index+1)%5; break; }
            else if(key==KEY_UP)
                { index=(index+4)%5; break; }
            else if(key==KEY_ENTER)
            {

                if(index>=0 && index<=3)
                {
                    index+=6; key='0';
                    break;
                }
                else if(index==4)
                    return true;
            }
            else if(key==KEY_ESC)
                return false;
        }
    }
    return false;
}



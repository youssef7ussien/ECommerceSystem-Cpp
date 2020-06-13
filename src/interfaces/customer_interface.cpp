#include <iostream>
#include "customer_interface.h"
#include "../data/category.h"
#include "../data/products.h"
#include "Graphics.h"

using namespace std;

void showBoxes(int x,int y,int column,int numberBoxes,int width=20)
{
    for(int i=0 ; i<numberBoxes ; i++)
        drawRectangle(x+(width+3)*(i%column),3*(i/column)+y,width,1);
}

void showCategoriesNames(int x,int y,int column,int index,const List<Category> &categories,int length)
{
    for(int i=0 ; i<length ; i++)
    {
        string name=categories.getCopyItem(i).getName();
        setCursor(x+(20+3)*(i%column)+2,3*(i/column)+y);
        index==i ? color(BLACK,RED) : color();
        cout<<" "<<name;
        clearLine(17-name.size());
    }
    color();
}

void productBox(int x,int y,const Product product)
{
    drawRectangle(x,y,25,7); // Border Box
    setCursor(x+2,y+1); cout<<product.getName();
    drawLine(x+2,y+2,x+24,y+2);
    setCursor(x+8,y+3); cout<<product.getPrice()<<" $";
    drawRectangle(x+14,y+5,9,1); // BUY Box

}

void productButtons(int x,int y,int numberProduct,int index=-1)
{
    string buttons[]={"  More  ","  Buy  "};
    for(int i=0 ; i<numberProduct*2 ; i++)
    {
        int coordX=x+(25+3)*((i/2)%4), coordY=9*((i/2)/4)+y+6;
        index==i ? color(BLACK,RED) : color();
        setCursor(i%2 ? coordX+16 : coordX+3,coordY); cout<<buttons[i%2];
    }
    color();
}

void statusBar(string name,string text="LOGOUT")
{
    drawRectangle(6,1,117,1,2); // Status Bar
    setCursor(8,2); cout<<"Hello, "; color(RED); cout<<name;
    setCursor(104,2); color(DARK_GRAY); cout<<"Press ";
    color(BROWN); cout<<"Esc"; color(DARK_GRAY); cout<<" to "<<text; color();
}

int showCategories(string customerName,const List<Category> &categories)
{
    system("cls");
    int numCategories=categories.getLength();
    statusBar(customerName,"BACK");
    setCursor(8,5); color(YELLOW); cout<<"All Categories"; color();
    drawLine(6,6,123,6,DARK_GRAY); // Line
    showBoxes(8,8,5,numCategories); // Categories Boxes
    char key='0',index=0;
    while(key!=KEY_ENTER)
    {
        showCategoriesNames(8,9,5,index,categories,numCategories);
        while(1)
        {
            char key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%numCategories; break; }
            else if(key==KEY_LEFT)
                { index=(index+numCategories-1)%numCategories; break; }
            else if(key==KEY_ENTER)
                return index;
            else if(key==KEY_ESC)
                    return -1;
        }
    }
}

int showProducts(string customerName,const List<Product> &products,string categoryName)
{
    int numberProducts=products.getLength(), remainingProducts=0, page=1, length=0;
    if(numberProducts>12)
        { remainingProducts=numberProducts-12; length=12; }
    else
        { remainingProducts=0; length=numberProducts; }

    bool nextPage=false, prevPage=false;
    while(1)
    {
        system("cls");
        char key='0'; int index=0,y=4;
        statusBar(customerName,"BACK");
        if(categoryName!="")
        {
            setCursor(8,y++); cout<<"Category : ";
            color(YELLOW); cout<<categoryName; color();
            drawLine(6,y,123,y,DARK_GRAY); // Line
            y++;
        }
        if(nextPage)
        {
            if(remainingProducts/12)
            {
                length=12; remainingProducts-=12;
            }
            else
            {
                length=remainingProducts; remainingProducts=0;
            }
            nextPage=false; page++;
        }
        else if(prevPage)
        {
            remainingProducts+=(length-2)/2;
            length=12;
            prevPage=false; page--;
        }

        for(int i=numberProducts-(remainingProducts+length) , j=0 ; i<numberProducts-remainingProducts ; i++, j++) // ProductBoxes
            productBox(9+(25+3)*(j%4),9*(j/4)+y,products.getCopyItem(i));
        setCursor(64,33); cout<<page; // page number
        length=length*2+2;
        while(key!=KEY_ENTER)
        {
            index<length-2 ? productButtons(9,y,(length-2)/2,index%(length-2)) : productButtons(9,y,(length-2)/2);
            if(index==length-2)
                remainingProducts+12<numberProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(59,33); cout<<" < "; color();
            if(index==length-1)
                remainingProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(67,33); cout<<" > "; color();
            while(1)
            {
                key=_getch();
                if(key=='n' && remainingProducts)
                    { nextPage=true; key=KEY_ENTER; break; }
                else if(key==12 && remainingProducts)
                    { nextPage=true; key=KEY_ENTER; break; }
                else if(key=='p' && remainingProducts+12<numberProducts)
                    { prevPage=true; key=KEY_ENTER;  break; }
                else if(key==KEY_RIGHT)
                    { index=(index+1)%length; break; }
                else if(key==KEY_LEFT)
                    { index=(index+length-1)%length; break; }
                else if(key==KEY_DOWN)
                {
                    index+8<length-2 ? index+=8 : index=length-2;
                    break;
                }
                else if(key==KEY_UP)
                {
                    index-8>=0 ? index-=8 : index=length-2;
                    break;
                }
                else if(key==KEY_ENTER)
                {
                    if(index==length-1 && remainingProducts)
                        { nextPage=true; break; }
                    else if(index==length-2 && remainingProducts+12<numberProducts)
                        { prevPage=true; break; }
                    else if(index<length-2)
                        return (index+24*(page-1)); // 24 -> number of buttons options
                }
                else if(key==KEY_ESC)
                    return -1;
            }
        }
    }
}

int firstPageOfCustomer(const Customer &customer,const Products &products)
{
    system("cls");
    char key='0';
    int index=0, numCategories=products.categoriesLength(), numProducts=products.productsLength();

    if(numProducts>4) numProducts=4;
    if(numCategories>10) numCategories=10;

    int numberButtons=numCategories+numProducts*2+4;

    statusBar(customer.getName());
    drawRectangle(6,4,14,1);
    if(!customer.cartLength()) color(DARK_GRAY);
    drawRectangle(23,4,19,1); color();
    if(customer.cartLength())
    {
        color(DARK_GRAY); drawRectangle(44,4,3,1); color();
        setCursor(46,5); cout<<customer.cartLength();
    }
    drawLine(6,7,123,7,DARK_GRAY);
    setCursor(7,8); color(YELLOW); cout<<"Categories"; color();
    showBoxes(8,9,5,numCategories); // Categories Boxes
    drawLine(25,18,103,18,DARK_GRAY);
    setCursor(8,19); color(YELLOW); cout<<"Products"; color();
    for(int i=0 ; i<numProducts ; i++) // ProductBoxes
        productBox(9+(25+3)*(i%4),9*(i/4)+20,products.getProductConst(i));

    setCursor(8,32); color(DARK_GRAY); cout<<"* Press ";
    color(BROWN); cout<<"F1"; color(DARK_GRAY); cout<<" for keyboard shortcuts"; color();

    while(key!=KEY_ENTER)
    {
        if(!customer.cartLength() && index==1 && key==KEY_RIGHT)
            index=2;
        if(!customer.cartLength() && index==1 && key==KEY_LEFT)
            index=0;

        if(index==0)
            color(BLACK,RED);
        setCursor(8,5); cout<<"   Search   "; color();
        if(index==1)
            color(BLACK,RED);
        if(!customer.cartLength()) color(DARK_GRAY);
        setCursor(25,5); cout<<"  Shopping Cart  "; color();
        showCategoriesNames(8,10,5,index-2,products.getCategories(),numCategories);

        if(index==numCategories+2)
            color(BLACK,RED);
        setCursor(54,16); cout<<"  Show all Categories  "; color();

        index>=numCategories && index<numberButtons ?
            productButtons(9,20,numProducts,index-numCategories-3) : productButtons(9,20,numProducts);

        if(index==numberButtons-1)
            color(BLACK,RED);
        setCursor(55,30); cout<<"  Show all Products  "; color();
        while(1)
        {
            key=_getch();
            if(key==KEY_F1)
                return -4;
            else if(key=='c')
                return -4;
            else if(key=='p')
                return -5;
            else if(key==KEY_RIGHT)
                { index=(index+1)%numberButtons; break; }
            else if(key==KEY_LEFT)
                { index=(index+numberButtons-1)%numberButtons; break; }
            else if(key==KEY_DOWN)
            {
                if(index<2)
                    index=2;
                else if(index+5<numCategories+2)
                    index+=5;
                else if(index==numberButtons-1)
                    index=0;
                else if(index==numCategories+2)
                    index+=1;
                else if(index>=numCategories+3)
                    index=numberButtons-1;
                else
                    index=numCategories+2;
                break;
            }
            else if(key==KEY_UP)
            {
                if(index==numberButtons-1 || index==numCategories+2)
                    index-=1;
                else if(index>=numCategories+2)
                    index=numCategories+2; // numCategories+2-1
                else if(index-5>=2)
                    index-=5;
                else if(index<2)
                    index=numberButtons-1;
                else
                    index=0;
                break;
            }
            else if(key==KEY_ENTER)
            {
                if(index==0)
                    return -2;
                else if(index==1)
                    return -3;
                else if(index==numCategories+2)
                    return -4;
                else if(index==numberButtons-1)
                    return -5;
                return index<numCategories+2 ? index-2 : index-3;
            }
            else if(key==KEY_ESC)
                return -1;
        }
    }
    return index;
}

void productBoxInfo(int x,int y,int number,const Product &product)
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

void searchPage(const List<Product> &products)
{
    system("cls");
    statusBar("dfgfdgf");
    drawRectangle(6,5,14,1);
    drawRectangle(22,5,42,1);

    drawRectangle(67,5,32,1);
    setCursor(67+11,5); cout<<char(194);
    setCursor(67+11,5+1); cout<<char(179);
    setCursor(67+11,5+2); cout<<char(193);

    setCursor(8,9); color(YELLOW); cout<<"Results."; color();
    drawLine(7,10,122,10,DARK_GRAY);

    char key='0';
    int index=1,numberButtons=2;
    string text="";
    while(key!=KEY_ENTER)
    {
        if(index==0)
            color(BLACK,RED);
        setCursor(8,6); cout<<"   Search   "; color();
        if(index==1)
        {
            initialBox(22,5,42,text.size());
            text="";
            text=inputText(text);
            drawRectangle(22,5,42,1);
            if(products.contain(text))
                productBox(15,11,products.search(text));
            else
            {
                setCursor(45,18); cout<<"There is no product with this name"; color();
            }
        }

        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%numberButtons; break; }
            else if(key==KEY_LEFT)
                { index=(index+numberButtons-1)%numberButtons; break; }
            else if(key==KEY_DOWN)
            {

                break;
            }
            else if(key==KEY_UP)
            {

                break;
            }
            else if(key==KEY_ENTER)
            {

            }
            else if(key==KEY_ESC)
                return ;
        }
    }
}

PurchaseData enterPurchaseData(double price)
{
    char key='0';  int index=1;
    PurchaseData PD;

    setCursor(55,4); cout<<"Price";
    drawRectangle(54,5,20,1); // Price box
    setCursor(56,6); cout<<price<<" $";

    setCursor(78,4); cout<<"Shipping Expenses";
    drawRectangle(77,5,20,1); // shippingExpenses box
    setCursor(79,6); cout<<PD.shippingExpenses(price)<<" $";

    setCursor(101,4); cout<<"Total Price";
    drawRectangle(100,5,20,1); // totalPrice box
    setCursor(102,6); cout<<PD.totalPrice(price)<<" $";

    drawRectangle(54,9,42,1); // firstName box
    setCursor(55,8); cout<<"Full Name";
    drawRectangle(54,13,42,1); // userName box
    setCursor(55,12); cout<<"Phone Number";
    drawRectangle(54,17,42,1); // email box
    setCursor(55,16); cout<<"Email";
    drawRectangle(54,21,42,1); // Country box
    setCursor(55,20); cout<<"Country";
    drawRectangle(54,25,42,1); // Address box
    setCursor(55,24); cout<<"Full Address";

    drawRectangle(50,28,14,1); // Again box

    while(key!=KEY_ENTER)
    {
        setCursor(52,29);
        if(index==0)  color(BLACK,RED);
        cout<<"   FINISH    "; color();

        if(index==1)
        {
            initialBox(54,9,42,PD.getName().size());
            PD.setName("");
            PD.setName(inputText(PD.getName()));
            drawRectangle(54,9,42,1);

            initialBox(54,13,42,PD.getPhoneNumber().size());
            PD.setPhoneNumber("");
            PD.setPhoneNumber(inputText(PD.getPhoneNumber()));
            drawRectangle(54,13,42,1);

            initialBox(54,17,42,PD.getEmail().size());
            PD.setEmail("");
            PD.setEmail(inputText(PD.getEmail()));
            drawRectangle(54,17,42,1);
//
//            initialBox(54,21,42,PD.getCountry().size());
//            PD.setCountry("");
//            PD.setCountry(inputText(PD.getCountry()));
//            drawRectangle(54,21,42,1);

            initialBox(54,25,42,PD.getAddress().size());
            PD.setAddress("");
            PD.setAddress(inputText(PD.getAddress()));

            bool validation=true;
//            if(!PD.validationUsername())
//            {
//                validation=false;
//                setCursor(89,11); color(DARK_RED);
//                cout<<"Incorrect username";
//            }
//            if(!PD.validationEmail())
//            {
//                validation=false;
//                setCursor(89,15); color(DARK_RED);
//                cout<<"Incorrect email";
//            }
//            if(!PD.validationPassword())
//            {
//                validation=false;
//                setCursor(89,19); color(DARK_RED);
//                cout<<"Incorrect password";
//            }
//            if(!PD.confirmPassword(confirmPassword))
//            {
//                validation=false;
//                setCursor(89,23); color(DARK_RED);
//                cout<<"Password does not match";
//            }
            color();
            if(validation)
                return PD;
            drawRectangle(54,25,42,1);
            index=0;
            continue;
        }
        while(1)
        {
            key=_getch();
//            if(key==KEY_RIGHT)
//                { index=(index+1)%2; break; }
//            else if(key==KEY_LEFT)
//                { index=(index+3)%2; break; }
            if(key==KEY_ENTER)
                break;
        }
        if(key==KEY_ENTER && index==0)
        {
            key='0';
            index=1;
//            setCursor(89,11); cout<<"                       ";
//            setCursor(89,15); cout<<"                       ";
//            setCursor(89,19); cout<<"                       ";
//            setCursor(89,23); cout<<"                       ";
        }
    }
    return PD;
}

int showCart(Customer &customer,Queue<Product> *products)
{
    system("cls");
    statusBar(customer.getName());
    int length=products->getLength();
    double price=0.0;
    for(int i=0 , y=4 ; i<length ; i++ , y+=3) // ProductBoxes
    {
        Product product=products->dequeue();
        productBoxInfo(6,y,i+1,product);
        price+=product.getPrice();
    }
    drawLine(52,4,52,20);
    customer.createPurchaseData(enterPurchaseData(price));
    system("pause");
}

string nameDialog()
{
    color(YELLOW); drawRectangle(38,8,54,6); color();
    setCursor(39,9); clearLine(52);
    setCursor(39,11); clearLine(52);
    setCursor(39,13); clearLine(52);
    setCursor(39,14); clearLine(52);
    setCursor(41,9); cout<<"Enter your name";
    color(RED); drawRectangle(40,10,50,1); color();
    setCursor(42,11);
    string name="";
    char character=getchar();
    while(1)
    {
        if(character=='\n')
        {
            return name;
            break;
        }
        name+=character;
        character=getchar();
    }
    return name;
}

void buyDialog(const Customer &customer,string productName)
{
    system("cls");
    statusBar(customer.getName());
    for(int i=0 ; i<8 ; i++)
        { setCursor(36,i+12); clearLine(57); }
    color(YELLOW); drawRectangle(37,12,53,6); color();
    setCursor(40,13); color(GREEN); cout<<productName;
    color(); cout<<", Added to shopping cart.";
    setCursor(40,15); color(DARK_GRAY); cout<<"The shopping cart contains ";
    color(YELLOW); cout<<customer.cartLength();
    color(DARK_GRAY); cout<<" products";
    color(); drawRectangle(80,16,8,1);
//    setCursor(82,17); color(BLACK,YELLOW); cout<<"  OK  "; color();

    char key='0';
    int index=0;
    while(1)
    {
        if(index==0) color(BLACK,YELLOW);
            setCursor(82,17); cout<<"  OK  "; color();
        while(1)
        {
            char key=getch();
            if(key==KEY_LEFT || key==KEY_DOWN)
                { index=(index+1)%2; break; }
            else if(key==KEY_RIGHT || key==KEY_UP)
                { index=(index+3)%2; break; }
            else if(key==KEY_ENTER && index==0)
                return ;
            else if(key==KEY_ESC)
                    return ;
        }
    }
}
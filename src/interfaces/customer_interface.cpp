#include <iostream>
#include "customer_interface.h"
#include "../data/product.h"
#include "Graphics.h"

using namespace std;

int showBoxes(int x,int y,int column,int numberBoxes,int width=20)
{
    for(int i=0 ; i<numberBoxes ; i++)
        drawRectangle(x+(width+3)*(i%column),3*(i/column)+y,width,1);
    return 3*((numberBoxes-1)/column)+y;
}

void showCategoriesNames(int x,int y,int column,int index,vector<string> categories)
{
    for(int i=0 ; i<categories.size() ; i++)
    {
        setCursor(x+(20+3)*(i%column)+2,3*(i/column)+y+1);
        index==i ? color(BLACK,RED) : color();
        cout<<" "<<categories[i]; clearLine(17-categories[i].size());
    }
    color();
}

void productBoxe(int x,int y,const Product product)
{
    drawRectangle(x,y,25,7); // Border Box
    setCursor(x+2,y+1); cout<<product.getName();
    drawLine(x+2,y+2,x+24,y+2);
    setCursor(x+8,y+3); cout<<product.getPrice()<<" $";
    drawRectangle(x+14,y+5,9,1); // BUY Box

}

void showProductBoxes(int x,int y,int numberProduct)
{
    for(int i=0 ; i<numberProduct ; i++)
    {
        int coordX=x+(25+3)*(i%4), coordY=9*(i/4)+y;
        drawRectangle(coordX,coordY,25,7); // Border Box
        setCursor(coordX+2,coordY+1); cout<<"test test etst";
        drawLine(coordX+2,coordY+2,coordX+24,coordY+2);
        setCursor(coordX+8,coordY+3); cout<<"dsf6688 $";
        drawRectangle(coordX+14,coordY+5,9,1); // BUY Box
    }
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

int showAllProducts(const Products &products)
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
        char key='0'; int index=0;
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
            productBoxe(9+(25+3)*(j%4),9*(j/4)+1,products.getProductConst(i));
        drawRectangle(55,29,5,1); // prevPage
        drawRectangle(67,29,5,1); // nextPage
        setCursor(64,30); cout<<page; // page number
        length=length*2+2;
        while(key!=KEY_ENTER)
        {
            setCursor(0,0);cout<<index<<"  "<<length;
            index<length-2 ? productButtons(9,1,(length-2)/2,index%(length-2)) : productButtons(9,1,(length-2)/2);
            if(index==length-2)
                remainingProducts+12<numberProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(57,30); cout<<" < "; color();
            if(index==length-1)
                remainingProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(69,30); cout<<" > "; color();
            while(1)
            {
                key=getch();
                if(key==KEY_RIGHT)
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

int firstPageOfCustomer(const Customer &customer,vector<string> categories)
{
    system("cls");
    char key='0';
    int index=0, y=1, numCategories=categories.size(), numProducts=customer.getProducts().getLength();
    if(numProducts>4)
        numProducts=4;
    int numberButtons=numCategories+1+numProducts*2;
    drawRectangle(6,y,117,1,2); // Status Bar
    y=showBoxes(8,4,5,numCategories)+4; // Categories Boxes
    drawLine(6,y-1,123,y-1); // Line
    for(int i=0 ; i<numProducts ; i++) // ProductBoxes
        productBoxe(9+(25+3)*(i%4),9*(i/4)+y,customer.getProductConst(i));
    while(key!=KEY_ENTER)
    {
        showCategoriesNames(8,4,5,index,categories);
        index>=numCategories && index<numberButtons ?
            productButtons(9,y,numProducts,index-numCategories) : productButtons(9,y,numProducts);
        if(index==numberButtons-1)
            color(BLACK,RED);
        setCursor(55,y+10); cout<<"  Show all products  "; color();
        while(1)
        {
            key=getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%numberButtons; break; }
            else if(key==KEY_LEFT)
                { index=(index+numberButtons-1)%numberButtons; break; }
            else if(key==KEY_DOWN)
            {
                if(index+5<numCategories)
                    index+=5;
                else if(index==numberButtons-1)
                    index=0;
                else if(index>=numCategories)
                    index=numberButtons-1;
                else
                    index=numCategories;
                break;
            }
            else if(key==KEY_UP)
            {
                if(index==numberButtons-1)
                    index-=1;
                else if(index>=numCategories)
                    index=numCategories-1;
                else if(index-5>=0)
                    index-=5;
                else
                    index=numberButtons-1;
                break;
            }
            else if(key==KEY_ENTER)
                return index==numberButtons-1 ? -2 : index;
            else if(key==KEY_ESC)
                    return -1;
        }
    }
    return index;
}

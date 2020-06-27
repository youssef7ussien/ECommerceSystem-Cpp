#include <iomanip>
#include "admin_interface.h"
#include "functions.h"
#include "graphics.h"

void sellerBox(int x,int y,int number,const Seller seller)
{
    drawRectangle(x,y,44,1);
    setCursor(x+5,y); cout<<char(194);
    setCursor(x+2,y+1); cout<<number;
    setCursor(x+5,y+1); cout<<char(179);
    setCursor(x+5,y+2); cout<<char(193);
    setCursor(x+7,y+1); cout<<seller.getName();
    setCursor(x+31,y); cout<<char(194);
    setCursor(x+31,y+1); cout<<char(179);
    setCursor(x+31,y+2); cout<<char(193);
    setCursor(x+33,y+1); cout<<setw(3)<<seller.numberProducts();
    color(DARK_GRAY); cout<<" Product"; color();
    drawRectangle(x+46,y,23,1);
    setCursor(x+57,y); cout<<char(194);
    setCursor(x+57,y+1); cout<<char(179);
    setCursor(x+57,y+2); cout<<char(193);
}

void requestBox(int x,int y,int number,const Seller request)
{
    drawRectangle(x,y,3,1);
    setCursor(x+2,y+1); cout<<number;
    if(number==1)
    {
        drawRectangle(x+6,y,33,1);
        setCursor(x+23,y); cout<<char(194);
        setCursor(x+23,y+1); cout<<char(179);
        setCursor(x+23,y+2); cout<<char(193);
    }
    y+=3;

    number==1 ? drawRectangle(x,y,39,8) : drawRectangle(x,y,39,2);
    setCursor(x+2,y+1); color(DARK_GRAY); cout<<"Name :"; color();
    setCursor(x+3,y+2); cout<<request.getName();
    if(number==1)
    {
        drawLine(x+2,y+3,x+38,y+3,DARK_GRAY);
        setCursor(x+2,y+4); color(DARK_GRAY); cout<<"Username :"; color();
        setCursor(x+3,y+5); cout<<request.getUserName();
        drawLine(x+2,y+6,x+38,y+6,DARK_GRAY);
        setCursor(x+2,y+7); color(DARK_GRAY); cout<<"Email :"; color();
        setCursor(x+3,y+8); cout<<request.getEmail();
    }

}

void requestsBoxes(Queue<Seller> requests)
{
    int length=requests.getLength()>2 ? 2 : requests.getLength();
    if(requests.getLength()>2)
    {
        drawLine(15,28,35,28,DARK_GRAY);
        setCursor(17,29); color(RED); cout<<requests.getLength()-2<<" more requests"; color();
    }
    for(int i=0; i<length ; i++)
        requestBox(7,7+13*i,i+1,requests.dequeue());
}

void sellerButtonName(int x,int y,int numberProduct,int index=-1)
{
    string buttons[]={"  Show  ","  Delete  "};
    for(int i=0 ; i<numberProduct*2 ; i++)
    {
        index==i ? color(BLACK,RED) : color();
        setCursor(x+11*(i%2),3*(i/2)+y+1); cout<<buttons[i%2];
    }
    color();
}

void productButtonName(int x,int y,int numberProduct,int index=-1)
{
    for(int i=0 ; i<numberProduct ; i++)
    {
        index==i ? color(BLACK,RED) : color();
        setCursor(x,3*i+y+1); cout<<"  Show  ";
    }
    color();
}

int keyboardControlAdmin(int page,int numButtons,int remainingSellers,int numberSellers,bool isRequests) // use in firstPageOfSeller()
{
    if(!isRequests)
        { setCursor(13,15); cout<<"There are no requests yet"; }
    char key='0'; int index=0;
    while(key!=KEY_ENTER)
    {
        isRequests ? sellerButtonName(101,7,(numButtons-4)/2,index) : sellerButtonName(101,7,(numButtons-2)/2,index);
        if(isRequests)
        {
            if(index==numButtons-4) color(BLACK,RED);
            setCursor(15,8); cout<<"   Confirm    "; color();

            if(index==numButtons-3) color(BLACK,RED);
            setCursor(32,8); cout<<"    Reject    "; color();
        }

        if(index==numButtons-2)
            remainingSellers+8<numberSellers ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
        setCursor(84,32); cout<<" < "; color();
        if(index==numButtons-1)
            remainingSellers ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
        setCursor(92,32); cout<<" > "; color();

        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%numButtons; break; }
            else if(key==KEY_LEFT)
                { index=(index+numButtons-1)%numButtons; break; }
            else if(key==KEY_DOWN)
            {
                index+2<numButtons-2 ? index+=2 : index=numButtons-2; // 2 -> number of buttons in per row
                break;
            }
            else if(key==KEY_UP)
            {
                index-2>=0 ? index-=2 : index=numButtons-2; // 2 -> number of buttons in per row
                break;
            }
            else if(key==KEY_ENTER)
            {
                int x= isRequests ? 4 : 2;
                if(index==numButtons-1 && remainingSellers)
                    return -6;
                else if(index==numButtons-2 && remainingSellers+8<numberSellers)
                    return -5;
                else if(isRequests && index==numButtons-3)
                    return -4;
                else if(isRequests && index==numButtons-4)
                    return -3;
                else if(index<numButtons-x)
                    return (index+16*(page-1));
            }
            else if(key==KEY_ESC) // for back
                return -1;
            else if(key=='p')
                return -2;
            else if(isRequests && key=='c')
                return -3;
            else if(isRequests && key=='r')
                return -4;
            else if(key=='b' && remainingSellers+8<numberSellers)
                return -5;
            else if(key=='n' && remainingSellers)
                return -6;
        }
    }
    return -1;
}

int keyboardControlAdmin() // use in firstPageOfSeller()
{
    setCursor(70,15); cout<<"There are no Sellers yet";
    char key='0'; int index=0;
    while(key!=KEY_ENTER)
    {
        if(index==0) color(BLACK,RED);
        setCursor(15,8); cout<<"   Confirm    "; color();

        if(index==1) color(BLACK,RED);
        setCursor(32,8); cout<<"    Reject    "; color();

        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT || key==KEY_LEFT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index==0 ? -3 : -4;
            else if(key==KEY_ESC) // for back
                return -1;
            else if(key=='p')
                return -2;
            else if(key=='c')
                return -3;
            else if(key=='r')
                return -4;
        }
    }
    return -1;
}

int firstPageOfAdmin(const Admin &admin)
{
    int numberSellers=admin.numberSellers(), remainingSellers=0, page=1, length=0;
    bool nextPage=false, prevPage=false;
    if(numberSellers>8) // 8 -> The number of sellers per page
        { remainingSellers=numberSellers-8; length=8; }
    else
        { remainingSellers=0; length=numberSellers; }

    while(1)
    {
        system("cls");
        statusBar(admin.getFirstName(),"LOGOUT",true);
        setCursor(25,5); color(YELLOW); cout<<"Requests"; color();
        drawLine(6,6,48,6,DARK_GRAY);
        drawLine(50,5,50,30,DARK_GRAY);
        setCursor(78,5); color(YELLOW); cout<<"Sellers"; color();
        drawLine(52,6,124,6,DARK_GRAY);

        if(admin.numberRequests()!=0 && admin.numberSellers()==0)
        {
            requestsBoxes(admin.getRequests().copy());
            return keyboardControlAdmin();
        }
        else if(admin.numberRequests()==0 && admin.numberSellers()==0)
        {
            setCursor(70,15); cout<<"There are no Sellers yet";
            setCursor(13,15); cout<<"There are no requests yet";
            while(1)
            {
                char key=_getch();
                if(key==KEY_ESC) // for back
                    return -1;
                else if(key=='p')
                    return -2;
            }
        }
        else
        {
            if(admin.numberRequests()!=0)
                requestsBoxes(admin.getRequests().copy());
            if(nextPage)
            {
                if(remainingSellers/8)
                    { length=8; remainingSellers-=8; }
                else
                    { length=remainingSellers; remainingSellers=0; }
                nextPage=false; page++;
            }
            else if(prevPage)
            {
                remainingSellers+=length;
                length=8;
                prevPage=false; page--;
            }

            for(int i=numberSellers-(remainingSellers+length),y=7 ; i<numberSellers-remainingSellers ; i++, y+=3)
                sellerBox(53,y,i+1,admin.getSellerConst(i));
            setCursor(89,32); cout<<page; // page number

            int result=keyboardControlAdmin(page, admin.numberRequests()==0 ? length*2+2 : length*2+4 ,
                                            remainingSellers,numberSellers,admin.numberRequests()!=0);
            if(result==-6)
                nextPage=true;
            else if(result==-5)
                prevPage=true;
            else
                return result;
        }
    }
}

void sellerCard(const Seller &seller)
{
    setCursor(13,8); color(DARK_GRAY); cout<<"Name"; color();
    drawRectangle(12,9,40,1);
    setCursor(14,10); cout<<seller.getName();

    setCursor(13,13); color(DARK_GRAY); cout<<"Username"; color();
    drawRectangle(12,14,40,1);
    setCursor(14,15); cout<<seller.getUserName();

    setCursor(13,18); color(DARK_GRAY); cout<<"Email"; color();
    drawRectangle(12,19,40,1);
    setCursor(14,20); cout<<seller.getEmail();

    drawRectangle(19,23,25,1);
    setCursor(21,24); color(YELLOW); cout<<"Number of products "; color();
    cout<<setw(3)<<seller.numberProducts();
}

int sellerPage(const Seller &seller,const Products &products)
{
    int numberProduct=seller.numberProducts(), remainingProduct=0, page=1, length=0;
    bool nextPage=false, prevPage=false;
    if(numberProduct>8) // 8 -> The number of products per page
        { remainingProduct=numberProduct-8; length=8; }
    else
        { remainingProduct=0; length=numberProduct; }

    while(1)
    {
        system("cls");
        char key='0'; int index=0;
        statusBar("Admin","BACK",true);
        setCursor(24,5); color(YELLOW); cout<<"Seller information"; color();
        drawLine(10,6,55,6,DARK_GRAY);
        setCursor(81,5); color(YELLOW); cout<<"Seller products"; color();
        drawLine(59,6,120,6,DARK_GRAY);

        sellerCard(seller);
        drawLine(57,5,57,30,DARK_GRAY);

        if(nextPage)
        {
            if(remainingProduct/8)
                { length=8; remainingProduct-=8; }
            else
                { length=remainingProduct; remainingProduct=0; }
            nextPage=false; page++;
        }
        else if(prevPage)
        {
            remainingProduct+=(length-3);
            length=8;
            prevPage=false; page--;
        }

        if(numberProduct!=0)
        {
            for(int i=numberProduct-(remainingProduct+length),y=7 ; i<numberProduct-remainingProduct ; i++, y+=3)
                productBox(61,y,i+1,products.getCopyProduct(seller.getProductId(i)),1);
            setCursor(89,32); cout<<page; // page number
            length=length+3; // 3 -> next , previous , add product
        }
        else
        {
            setCursor(75,15); cout<<"There are no products yet";
            length=0;
        }
        while(key!=KEY_ENTER)
        {
            if(numberProduct!=0)
            {
                productButtonName(109,7,length-3,index); // 3 -> next , previous , add product
                if(index==length-2)
                    remainingProduct+8<numberProduct ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
                setCursor(84,32); cout<<" < "; color();
                if(index==length-1)
                    remainingProduct ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
                setCursor(92,32); cout<<" > "; color();
            }
            while(1)
            {
                key=_getch();
                if(key==KEY_RIGHT)
                    { index=(index+1)%length; break; }
                else if(key==KEY_LEFT)
                    { index=(index+length-1)%length; break; }
                else if(key==KEY_DOWN)
                    { index=(index+1)%length; break; }
                else if(key==KEY_UP)
                    { index=(index+length-1)%length; break; }
                else if(key==KEY_ENTER)
                {
                    if(index==length-1 && remainingProduct)
                        { nextPage=true; break; }
                    else if(index==length-2 && remainingProduct+8<numberProduct)
                        { prevPage=true; break; }
                    else if(index==length-3)
                        return -1;
                    else if(index<length-3)
                        return seller.getProductId(index+8*(page-1)); // 24 -> number of buttons options
                }
                else if(key==KEY_ESC) // for back
                    return -2;
            }
        }
    }
}

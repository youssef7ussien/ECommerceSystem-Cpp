#include <conio.h>
#include "Interfaces.h"
#include "seller_interface.h"
#include "customer_interface.h"
#include "Account.h"
#include <regex>
#include <iostream>

using namespace std;

int interfaceLoginAs()
{
    system("cls");
    char key=80;  int index=0;

    drawRectangle(50,1,30,1,2); // login as box
    setCursor(62,2); cout<<"Login as";
    drawRectangle(55,4,20,1); // Admin box
    drawRectangle(55,7,20,1); // Seller box
    drawRectangle(55,10,20,1); // Customer box
    drawRectangle(55,13,20,1); // Register box
    drawLine(50,16,82,16);
    drawRectangle(67,17,14,1); // Exit box

    while(key!=13)
    {
        if(index==0)  color(BLACK,RED);
        setCursor(57,5); cout<<"      Admin       "; color();

        if(index==1)  color(BLACK,RED);
        setCursor(57,8); cout<<"      Seller      "; color();

        if(index==2)  color(BLACK,RED);
        setCursor(57,11); cout<<"     Customer     "; color();

        if(index==3)  color(BLACK,RED);
        setCursor(57,14); cout<<"     Register     "; color();

        setCursor(69,18);
        if(index==4)  color(BLACK,RED);
        cout<<"    EXIT    "; color();
        setCursor(0,28);
        while(1)
        {
            key=getch();
            if(key==KEY_DOWN)
                { index=(index+1)%5; break; }
            else if(key==KEY_UP)
                { index=(index+4)%5; break; }
            else if(key==KEY_ENTER)
                return index;
            else if(key==KEY_ESC)
                    return 4;
        }
    }
    return index;
}

bool interfaceLogin()
{
    system("cls");
    char key=80;  int index=2;
    string username,password;
    drawRectangle(50,1,30,1,2); // login box
    setCursor(62,2); cout<<"Login";
    drawRectangle(45,6,40,1); // email box
    setCursor(46,5); cout<<"Enter email";
    drawRectangle(45,10,40,1); // password box
    setCursor(46,9); cout<<"Enter password";
    drawRectangle(50,14,14,1); // Again box
    drawRectangle(66,14,14,1); // Exit box

    while(key!=13)
    {
        setCursor(52,15);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,15);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            editCursor(true);
            color(RED);
            drawRectangle(45,6,40,1);
            color();
            setCursor(47,7);
            clearLine(username.size());
            setCursor(47,7);
            username="";
            char firstchar=getchar();
            while(1)
            {
                if(firstchar=='\n')
                {
                    index=3;
                    break;
                }
                username+=firstchar;
                firstchar=getchar();
            }
            drawRectangle(45,6,40,1);
        }
        color();
        if(index==3)
        {
            color(RED);
            drawRectangle(45,10,40,1);
            color();
            setCursor(47,11);
            clearLine(password.size());
            setCursor(47,11);
            password="";
            char firstchar=getchar();
            while(1)
            {
                if(firstchar=='\n')
                {
                    index=0;
                    break;
                }
                password+=firstchar;
                firstchar=getchar();
            }
            editCursor(false);
            if(username=="admin" && password=="admin") return true;

            setCursor(44,13); color(DARK_RED);
            cout<<"Incorrect email or password please try again";
            color();
            drawRectangle(45,10,40,1);
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
            setCursor(44,13);
            cout<<"                                            ";
        }
    }
    return false;
}

bool interfaceRegister()
{
    system("cls");
    char key=80;  int index=2;
    drawRectangle(50,1,30,1,2); // login box
    setCursor(64,2); cout<<"Register";
    drawRectangle(44,6,20,1); // firstName box
    setCursor(45,5); cout<<"First name";
    drawRectangle(66,6,20,1); // lastName box
    setCursor(67,5); cout<<"Last name";
    drawRectangle(44,10,42,1); // userName box
    setCursor(45,9); cout<<"username";
    drawRectangle(44,14,42,1); // email box
    setCursor(45,13); cout<<"Email";
    drawRectangle(44,18,42,1); // password box
    setCursor(45,17); cout<<"Password";
    drawRectangle(44,22,42,1); // confirm password box
    setCursor(45,21); cout<<"Confirm Password";
    drawRectangle(50,25,14,1); // Again box
    drawRectangle(66,25,14,1); // Exit box
    string confirmPassword;
    Account newAccount;
    while(key!=13)
    {
        setCursor(52,26);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,26);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2) // first name
        {
            editCursor(true);
            color(RED);
            drawRectangle(44,6,20,1);
            color();
            setCursor(46,7);
            clearLine(newAccount.getFirstName().size());
            setCursor(46,7);
            newAccount.setFirstName("");
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=3;
                    break;
                }
                newAccount.setFirstName(newAccount.getFirstName()+character);
                character=getchar();
            }
            drawRectangle(44,6,20,1);
        }
        if(index==3) // last name
        {
            editCursor(true);
            color(RED);
            drawRectangle(66,6,20,1);
            color();
            setCursor(68,7);
            clearLine(newAccount.getLastName().size());
            setCursor(68,7);
            newAccount.setLastName("");
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=4;
                    break;
                }
                newAccount.setLastName(newAccount.getLastName()+character);
                character=getchar();
            }
            drawRectangle(66,6,20,1);
        }
        if(index==4) // username
        {
            editCursor(true);
            color(RED);
            drawRectangle(44,10,42,1);
            color();
            setCursor(46,11);
            clearLine(newAccount.getUserName().size());
            setCursor(46,11);
            newAccount.setUserName("");
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=5;
                    break;
                }
                newAccount.setUserName(newAccount.getUserName()+character);
                character=getchar();
            }
            drawRectangle(44,10,42,1);
        }
        if(index==5) // email
        {
            editCursor(true);
            color(RED);
            drawRectangle(44,14,42,1);
            color();
            setCursor(46,15);
            clearLine(newAccount.getEmail().size());
            setCursor(46,15);
            newAccount.setEmail("");
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=6;
                    break;
                }
                newAccount.setEmail(newAccount.getEmail()+character);
                character=getchar();
            }
            drawRectangle(44,14,42,1);

        }
        if(index==6) // password
        {
            editCursor(true);
            color(RED);
            drawRectangle(44,18,42,1);
            color();
            setCursor(46,19);
            clearLine(newAccount.getPassword().size());
            setCursor(46,19);
            newAccount.setPassword("");
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=7;
                    break;
                }
                newAccount.setPassword(newAccount.getPassword()+character);
                character=getchar();
            }
            drawRectangle(44,18,42,1);
        }
        if(index==7) // confirm password
        {
            color(RED);
            drawRectangle(44,22,42,1);
            color();
            setCursor(46,23);
            clearLine(confirmPassword.size());
            setCursor(46,23);
            confirmPassword="";
            char character=getchar();
            while(1)
            {
                if(character=='\n')
                {
                    index=0;
                    break;
                }
                confirmPassword+=character;
                character=getchar();
            }
            editCursor(false);
            bool validation=true;
            if(!newAccount.validationUsername())
            {
                validation=false;
                setCursor(89,11); color(DARK_RED);
                cout<<"Incorrect username";
            }
            if(!newAccount.validationEmail())
            {
                validation=false;
                setCursor(89,15); color(DARK_RED);
                cout<<"Incorrect email";
            }
            if(!newAccount.validationPassword())
            {
                validation=false;
                setCursor(89,19); color(DARK_RED);
                cout<<"Incorrect password";
            }
            if(!newAccount.confirmPassword(confirmPassword))
            {
                validation=false;
                setCursor(89,23); color(DARK_RED);
                cout<<"Password does not match";
            }
            color();
            if(validation) return true;
            drawRectangle(44,22,42,1);
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
            setCursor(89,11); cout<<"                       ";
            setCursor(89,15); cout<<"                       ";
            setCursor(89,19); cout<<"                       ";
            setCursor(89,23); cout<<"                       ";
        }
    }
    return false;
}

bool interfaceExitGame(int x,int y)
{
    char key='0';  int index=0;
    drawRectangle(x,y,43,5); //35 11
    setCursor(x+1,y+1); color();
    cout<<"               Are You Sure ?              ";
    setCursor(x+1,y+2); clearLine(43);
    setCursor(x+1,y+3); clearLine(43);
    setCursor(x+1,y+4); clearLine(43);
    setCursor(x+1,y+5); clearLine(43);
    drawRectangle(x+2,y+3,11,1);
    drawRectangle(x+33,y+3,8,1);

    while(key!=KEY_ENTER)
    {
        setCursor(x+4,y+4); color();
        if(index==1)  color(BLACK,RED);
        cout<<"   YES   "; color();

        setCursor(x+35,y+4);
        if(index==0)  color(BLACK,RED);
        cout<<"  NO  "; color();
        setCursor(0,26);
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
    }
    return index==1 ? true : false;

//    else
//    {
//        if(!exitGame)
//            for(int i=0;i<6;i++)
//            {
//                setCursor(35,11+i);
//                cout<<"                                                 ";
//            }
//        return 0;
//    }
}

void productDetails(int x,int y,const Product product,User user=CUSTOMER) // Use in Seller , Customer , Admin
{
    system("cls");
    drawRectangle(x,y,83,14); // Border Box
    drawRectangle(x+2,y+1,60,1); // Name Box
    setCursor(x+4,y+2); cout<<product.getName();
    drawRectangle(x+66,y+1,15,1); // Price Box
    setCursor(x+68,y+2); cout<<product.getPrice();
    setCursor(x+3,y+4); cout<<product.getDescription(); // Description
    switch(user)
    {
        case CUSTOMER:
        {
            drawRectangle(x+21,y+11,39,1); // BUY Box
            setCursor(x+39,y+12); cout<<"BUY";
        } break;
        case SELLER:
        {
            drawRectangle(x+21,y+11,16,1);
            setCursor(x+28,y+12); cout<<"Edit";
            drawRectangle(x+50,y+11,16,1);
            setCursor(x+56,y+12); cout<<"Delete";
        } break;
        case ADMIN:
        {
            drawRectangle(x+21,y+11,39,1);
            setCursor(x+38,y+12); cout<<"Delete";
        } break;
    }
}

void interfaceSeller(Seller &seller)
{
    while(1)
    {
        int result=firstPageOfSeller(seller);//,length=seller.getProducts().getLength();
/*
    firstPageOfSeller() : This function returns three possibilities
        1- return -1 -> For back
        2- return -2 -> For add Product
        3- return value between 0 and ( number of product * 3 ) -> For operations on products : show , edit , delete
*/
        if(result==-2)
            return ;
        else if(result==-1)
            interfaceAddProduct();
        else if(!(result%3)) // For show Product
        {
            productDetails(15,1,seller.getProductConst(result/3),SELLER);  // 3 -> number of buttons in per row
            setCursor(0,31); system("pause");
        }
        else if(result%3==1) // For edit Product
        {
            interfaceEditProduct(seller.getProduct((result-1)/3));
            productDetails(15,1,seller.getProductConst((result-1)/3),SELLER);
            setCursor(0,31); system("pause");
        }
        else if(result%3==2) // For delete Product
        {
            productDetails(15,1,seller.getProductConst((result-2)/3),SELLER);  // 3 -> number of buttons in per row
            setCursor(0,31); system("pause");
        }
    }
}

void interfaceCustomer(const Customer &customer)
{
    system("cls");
    vector<string> categories={"Cameras","Books","Furniture","Electronics","Kitchen"};
    int numCategories=categories.size();
    while(1)
    {
        int result=firstPageOfCustomer(customer,categories);
        if(result==-1)
            return ;
        else if(result==-2)
        {
            int re=showAllProducts(customer.getProducts());
            if(re==-1)
                continue;
            else if(!(re%2)) // For More
            {
                productDetails(15,1,customer.getProductConst(re/2));  // 2 -> number of buttons in per box
                setCursor(0,31); system("pause");
            }
            else if(re%2) // For Buy
            {
                productDetails(15,1,customer.getProductConst(re/2));
                setCursor(0,31); system("pause");
            }
        }
        else if(result<numCategories)
            { setCursor(0,1); cout<<result<<"  "<<categories[result]; system("pause"); }
        else if(!((result-numCategories)%2))
        {
            productDetails(15,1,customer.getProductConst(result-numCategories));  // 3 -> number of buttons in per row
            setCursor(0,31); system("pause");
        }
        else if(((result-numCategories)%2))
            { setCursor(0,23); cout<<result%numCategories<<"  buttons :"<<result%2<<" , Product no. "<<(result%numCategories)/2; system("pause"); }
    }

}


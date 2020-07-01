#include "customer_interface.h"
#include "functions.h"
#include "graphics.h"
#include <iomanip>

void categoriesBoxes(int x,int y,int column,int numberBoxes)
{
    for(int i=0 ; i<numberBoxes ; i++)
        drawRectangle(x+23*(i%column),3*(i/column)+y,20,1);
}

void categoriesNames(int x,int y,int column,int index,const List<Category> &categories,int length)
{
    for(int i=0 ; i<length ; i++)
    {
        string name=categories.getCopyItemAt(i).getName();
        setCursor(x+(20+3)*(i%column)+2,3*(i/column)+y);
        index==i ? color(BLACK,RED) : color();
        cout<<" "<<name;
        clearLine(17-name.size());
    }
    color();
}

void productBigBox(int x,int y,const Product& product)
{
    drawRectangle(x,y,25,7); // Border Box
    if(product.getName().size()>21)
        { setCursor(x+2,y+1); cout<<product.getName().substr(0,20)<<"..."; }
    else
        { setCursor(x+2,y+1); cout<<product.getName(); }
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

int showCategories(const string& customerName,const List<Category> &categories)
{
    system("cls");
    int numCategories=categories.getLength();
    statusBar(customerName,"BACK");
    setCursor(8,5); color(YELLOW); cout<<"All Categories"; color();
    drawLine(6,6,123,6,DARK_GRAY); // Line
    categoriesBoxes(8,8,5,numCategories); // Categories Boxes
    int index=0;
    while(true)
    {
        categoriesNames(8,9,5,index,categories,numCategories);
        while(true)
        {
            char key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%numCategories; break; }
            else if(key==KEY_LEFT)
                { index=(index+numCategories-1)%numCategories; break; }
            if(key==KEY_UP)
                { index-5<0 ? index=numCategories-1 : index-=5; break; }
            else if(key==KEY_DOWN)
                { index+5>numCategories ? index=0 : index+=5; break; }
            else if(key==KEY_ENTER)
                return index;
            else if(key==KEY_ESC)
                    return -1;
        }
    }
}

int showProducts(const string& customerName,const List<Product> &products,const string& titlePage)
{
    int numberProducts=products.getLength(), remainingProducts=0, page=1, length=0;
    if(numberProducts>12)
        { remainingProducts=numberProducts-12; length=12; }
    else
        { remainingProducts=0; length=numberProducts; }

    bool nextPage=false, prevPage=false;
    while(true)
    {
        system("cls");
        char key='0'; int index=0,y=4;
        statusBar(customerName,"BACK");
        if(!titlePage.empty())
        {
            setCursor(8,y++);
            if(titlePage[0]=='*') // '*' -> search
            {
                cout<<"Search results for ' ";
                color(GREEN);  cout<<titlePage.substr(1); color();
                cout<<" ' , "; color(RED);  cout<<products.getLength();
                color(); cout<<" products found.";
            }
            else
            {
                cout<<"Category : "; color(YELLOW);
                cout<<titlePage; color();
            }
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
            productBigBox(9+(25+3)*(j%4),9*(j/4)+y,products.getCopyItemAt(i));
        setCursor(64,33); cout<<page; // page number
        length=length*2+2;
        while(key!=KEY_ENTER)
        {
            index<length-2 ? productButtons(9,y,(length-2)/2,index)
                             : productButtons(9,y,(length-2)/2);
            if(index==length-2)
                remainingProducts+12<numberProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(59,33); cout<<" < "; color();
            if(index==length-1)
                remainingProducts ? color(BLACK,RED) : color(BLACK,DARK_GRAY);
            setCursor(67,33); cout<<" > "; color();
            while(true)
            {
                key=_getch();
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
                        return(index+24*(page-1)); // 24 -> number of buttons options
                }
                else if(key==KEY_ESC)
                    return -1;
                else if(key=='n' && remainingProducts)
                    { nextPage=true; key=KEY_ENTER; break; }
                else if(key=='b' && remainingProducts+12<numberProducts)
                    { prevPage=true; key=KEY_ENTER;  break; }
            }
        }
    }
}

int firstPageOfCustomer(const Customer &customer,const Products &products)
{
    system("cls");
    char key='0';
    int index=0, numCategories=products.categoriesLength(),  numProducts=products.productsLength();

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
    categoriesBoxes(8,9,5,numCategories); // Categories Boxes
    drawLine(25,18,103,18,DARK_GRAY);
    setCursor(8,19); color(YELLOW); cout<<"Products"; color();
    for(int i=0 ; i<numProducts ; i++) // ProductBoxes
        productBigBox(9+(25+3)*(i%4),9*(i/4)+20,products.getCopyProductAt(i));

    setCursor(8,32); color(DARK_GRAY); cout<<"* Press ";
    color(BROWN); cout<<"F1"; color(DARK_GRAY); cout<<" for keyboard shortcuts"; color();

    while(true)
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
        categoriesNames(8,10,5,index-2,products.getCategories(),numCategories);

        if(index==numCategories+2)
            color(BLACK,RED);
        setCursor(54,16); cout<<"  Show all Categories  "; color();

        index>=numCategories && index<numberButtons ?
            productButtons(9,20,numProducts,index-numCategories-3) : productButtons(9,20,numProducts);

        if(index==numberButtons-1)
            color(BLACK,RED);
        setCursor(55,30); cout<<"  Show all Products  "; color();
        while(true)
        {
            key=_getch();
            if(key==KEY_RIGHT)
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
            else if(key=='s')
                return -2;
            else if(key=='t' && customer.cartLength())
                return -3;
            else if(key=='c')
                return -4;
            else if(key=='p')
                return -5;
            else if(key==KEY_F1)
                return -6;
        }
    }
    return index;
}

void searchField(int x,int y,int width,string &text)
{
    setCursor(x+width+3,y+1); cout<<"               ";
    initialBox(x,y,width,text.size(),1);
    while(true)
    {
        text=inputText();
        if(text.empty() || !validationRegex("^[a-zA-z0-9 \\-,]{1,30}$",text))
        {
            setCursor(x+2,y+1); clearLine(text.size());
            setCursor(x+width+3,y+1); cout<<"               "; wait(150);
            setCursor(x+width+3,y+1);
            color(DARK_RED); cout<<"Incorrect input";
            setCursor(x+2,y+1);
            color();
        }
        else
        {
            setCursor(x+width+3,y+1); cout<<"               ";
            drawRectangle(x,y,width,1);
            return;
        }
    }
}

string searchPage(const string& customerName,const List<Product> &products,List<Product> &productsFounded)
{
    system("cls");
    statusBar(customerName,"BACK");
    drawRectangle(6,5,14,1); // search box
    drawRectangle(22,5,42,1); // input box

    setCursor(8,9); color(YELLOW); cout<<"Results."; color();
    drawLine(7,10,122,10,DARK_GRAY);

    int index=-1;
    string text;
    while(true)
    {
        if(index==0) color(BLACK,RED);
        setCursor(8,6); cout<<"   Search   "; color();

        if(index==-1)
        {
            searchField(22,5,42,text);
            productsFounded=products.multiSearch(text);
            if(productsFounded.getLength())
                return text;
            else
            { setCursor(45,18); cout<<"There is no product with this name"; }
            index=0;
            continue;
        }

        while(true)
        {
            char key=_getch();
            if(key==KEY_RIGHT || key==KEY_LEFT|| key==KEY_DOWN || key==KEY_UP)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                { index=-1; break; }
            else if(key==KEY_ESC)
                return "";
        }
    }
}

string editField(int x,int y,const string& patternRegex,int width)
{
    string text;
    setCursor(x+width+3,y+1); cout<<"               ";
    initialBox(x,y,width,text.size(),1);
    while(true)
    {
        text=inputText();
        if(text.empty() || !validationRegex(patternRegex,text))
        {
            setCursor(x+2,y+1); clearLine(text.size());
            setCursor(x+width+3,y+1); cout<<"               "; wait(150);
            setCursor(x+width+3,y+1);
            color(DARK_RED); cout<<"Incorrect input";
            setCursor(x+2,y+1);
            color();
        }
        else
        {
            setCursor(x+width+3,y+1); cout<<"               ";
            color(GREEN); drawRectangle(x,y,width,1);
            setCursor(x+width+3,y+1); cout<<"Done";
            color();
            return text;
        }
    }
    return text;
}

int enterPurchaseData(PurchaseData &PD)
{
    clearMultiLines(64,10,3,52);
    drawRectangle(61,11,45,1); // Full Name box
    setCursor(62,10); cout<<"Full Name";
    drawRectangle(61,15,45,1); // Phone Number box
    setCursor(62,14); cout<<"Phone Number";
    drawRectangle(61,19,45,1); // email box
    setCursor(62,18); cout<<"Email";
    drawRectangle(61,23,45,1); // Country box
    setCursor(62,22); cout<<"Country";
    drawRectangle(61,27,45,1); // Address box
    setCursor(62,26); cout<<"Full Address";

    drawRectangle(61,30,12,1); // Cancel box
    drawRectangle(76,30,30,1); // Finish box

   int index=2;
    while(true)
    {
        if(index==1) color(BLACK,RED);
        setCursor(63,31); cout<<"  Cancel  "; color();
        if(index==0) color(BLACK,RED);
        setCursor(78,31); cout<<"  Finish and print invoice  "; color();

        if(index==2)
        {
            PD.setName(editField(61,11,"^[a-zA-z0-9 \\-,]{3,30}$",45));
            PD.setPhoneNumber(editField(61,15,"^\\d{11}$",45));
            PD.setEmail(editField(61,19,"^[\\w\\._]{3,21}@[\\w\\._]{2,11}\\.\\w{2,4}$",45));
            PD.setCountry(editField(61,23,"^[a-zA-z0-9 \\-,]{3,30}$",45));
            PD.setAddress(editField(61,27,"^[a-zA-z0-9 \\-,\\.]{3,40}$",45));
            index=0;
            continue;
        }

        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index==1 ? -1 : index;
            else if(key==KEY_ESC)
                return -1;
        }
    }
}

int showCart(const string& customerName,Queue<Product> products,PurchaseData &PD)
{
    system("cls");
    statusBar(customerName,"BACK");
    int length=products.getLength();
    double price=0.0;
    setCursor(20,5); color(YELLOW); cout<<"Your purchases"; color();
    for(int i=0 , y=6 ; i<length ; i++ , y+=3) // ProductBoxes
    {
        Product product=products.dequeue();
        productBox(7,y,i+1,product,0);
        price+=product.getPrice();
    }
    drawLine(54,5,54,32,DARK_GRAY);
    setCursor(57,5); color(YELLOW); cout<<"Price"; color();
    drawRectangle(56,6,20,1); // Price box
    setCursor(58,7); cout<<setw(16)<<setprecision(10)<<price<<" $";

    setCursor(80,5); color(YELLOW); cout<<"Shipping Expenses"; color();
    drawRectangle(79,6,20,1); // shippingExpenses box
    setCursor(81,7); cout<<setw(16)<<setprecision(10)<<PD.shippingExpenses(price)<<" $";

    setCursor(103,5); color(YELLOW); cout<<"Total Price"; color();
    drawRectangle(102,6,20,1); // totalPrice box
    setCursor(104,7); cout<<setw(16)<<setprecision(10)<<PD.totalPrice(price)<<" $";

    drawLine(58,9,121,9,DARK_GRAY);
    drawRectangle(64,10,27,1); // Complete box
    drawRectangle(94,10,20,1); // clear cart box
    int index=0;
    while(true)
    {
        if(index==0) color(BLACK,RED);
        setCursor(66,11); cout<<"  Complete the purchase  "; color();
        if(index==1) color(BLACK,RED);
        setCursor(96,11); cout<<"  Empty the cart  "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
            {
                if(index==1)
                    return 1;
               return enterPurchaseData(PD);
            }
            else if(key==KEY_ESC)
                return -1;
        }
    }
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
    string name=inputText();

    return !name.empty() ? name : "No Name";
}

void keyboardControlCustomerDialog(int x,int y,Colors background=RED)
{
    int index=0;
    while(true)
    {
        if(index==0) color(BLACK,background);
        setCursor(x,y); cout<<"  OK  "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_DOWN || key==KEY_RIGHT || key==KEY_UP)
                { index=(index+1)%2; break; }
            else if(key==KEY_ESC || (key==KEY_ENTER && index==0))
                return ;
        }
    }
}

void shortcutsCustomerDialog(const string& customerName)
{
    system("cls");
    statusBar(customerName,"BACK");
    setCursor(61,6); cout<<"Shortcuts";
    drawLine(58,7,72,7,DARK_GRAY);
    color(DARK_GRAY); drawRectangle(38,8,53,17); color();
    setCursor(42,10); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"F1 "; color(); cout<<" : To show shortcuts Dialog.";
    setCursor(42,12); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"t  "; color(); cout<<" : To go to the shopping cart page.";
    setCursor(42,14); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"s  "; color(); cout<<" : To go to the search page.";
    setCursor(42,16); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"c  "; color(); cout<<" : To show all Categories.";
    setCursor(42,18); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"p  "; color(); cout<<" : To show all Products.";
    setCursor(42,20); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"b  "; color(); cout<<" : To previous page.";
    setCursor(42,22); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"n  "; color(); cout<<" : To next page.";
    setCursor(42,24); color(DARK_GRAY); cout<<"- "; color(CYAN);
    cout<<"ECS"; color(); cout<<" : To back or logout.";
    drawRectangle(83,27,8,1);
    keyboardControlCustomerDialog(85,28);
}

void noProductDialog()
{
    color(RED); drawRectangle(38,7,53,6); color();
    for(int i=0 ; i<=5 ; i++)
        { setCursor(39,i+8); clearLine(52); }
    setCursor(46,9);
    cout<<"No sellers have added any products yet";
    drawRectangle(81,11,8,1);
    keyboardControlCustomerDialog(83,12);
}

void buyDialog(const Customer &customer,const string& productName)
{
    system("cls");
    statusBar(customer.getName());
    color(YELLOW); drawRectangle(37,12,53,6); color();
    setCursor(40,13); color(GREEN); cout<<productName;
    color(); cout<<", Added to shopping cart.";
    setCursor(40,15); color(DARK_GRAY); cout<<"The shopping cart contains ";
    color(YELLOW); cout<<customer.cartLength();
    color(DARK_GRAY); cout<<" products";
    color(); drawRectangle(80,16,8,1);
    keyboardControlCustomerDialog(82,17,YELLOW);
}

void cartFullDialog(const string& customerName)
{
    system("cls");
    statusBar(customerName,"BACK");
    color(RED); drawRectangle(34,12,60,8); color();
    setCursor(37,14);
    cout<<"Your shopping cart is full, please complete the purchase";
    setCursor(37,16);
    cout<<"process or empty the shopping cart to buy again.";
    color(); drawRectangle(84,18,8,1);
    keyboardControlCustomerDialog(86,19);
}

void outOfStockDialog(const string& customerName)
{
    system("cls");
    statusBar(customerName);
    color(RED); drawRectangle(34,12,60,6); color();
    setCursor(37,14); cout<<"This product is out of stock.";
    color(); drawRectangle(84,16,8,1);
    keyboardControlCustomerDialog(86,17);
}


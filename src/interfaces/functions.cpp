#include "functions.h"
#include "graphics.h"
#include <iomanip>
#include <regex>

string inputText()
{
    editCursor(true);
    string text="";
    char character=getchar();
    while(true)
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

bool validationRegex(const string &style,const string &text)
{
    regex pattern(style);
    return regex_match(text, pattern);
}

void initialBox(int x,int y,int width,int lengthLine,int height)
{
    setCursor(x+2,y+1);
    clearLine(lengthLine);
    color(RED); drawRectangle(x,y,width,height); color();
    setCursor(x+2,y+1);
}

void statusBar(const string& name,const string& text,bool isAdmin)
{
    drawRectangle(6,1,117,1,2);
    setCursor(8,2); cout<<"Hello, "; color(RED); cout<<name; color();
    if(isAdmin)
    {
        setCursor(102,1); cout<<char(209);
        setCursor(83,2); color(DARK_GRAY); cout<<"Press ";
        color(BROWN); cout<<"P"; color(DARK_GRAY);
        cout<<" to Profile "; color(); cout<<char(179);
        setCursor(102,3); cout<<char(207);
    }
    setCursor(104,2); color(DARK_GRAY); cout<<"Press ";
    color(BROWN); cout<<"Esc"; color(DARK_GRAY); cout<<" to "<<text; color();
}

bool logOutDialog(const string& name)
{
    system("cls");
    statusBar(name,"BACK");
    color(RED);
    drawRectangle(34,12,60,3);
    drawRectangle(34,17,29,1);
    drawRectangle(66,17,28,1);
    color();
    setCursor(37,14); cout<<"Are you sure you want to log out ?";

    int index=0;
    while(true)
    {
        if(index==1)  color(BLACK,RED);
        setCursor(36,18); cout<<"            YES            "; color();

        if(index==0)  color(BLACK,RED);
        setCursor(68,18); cout<<"            NO            "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_RIGHT || key==KEY_LEFT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index==1;
            else if(key==KEY_ESC)
                return false;
        }
    }
}

void productBox(int x,int y,int number,const Product &product,int numOption)
{
    if(numOption!=0 && product.outOfStock())
        color(DARK_GRAY);
    drawRectangle(x,y,44,1);
    setCursor(x+2,y+1); cout<<number;
    setCursor(x+5,y); cout<<char(194);
    setCursor(x+5,y+1); cout<<char(179);
    setCursor(x+5,y+2); cout<<char(193);
    if(product.getName().size()>21)
        { setCursor(x+7,y+1); cout<<product.getName().substr(0,20)<<"..."; }
    else
        { setCursor(x+7,y+1); cout<<product.getName(); }
    setCursor(x+31,y); cout<<char(194);
    setCursor(x+31,y+1); cout<<char(179);
    setCursor(x+31,y+2); cout<<char(193);
    setCursor(x+33,y+1); cout<<setw(9)<<setprecision(8)<<product.getPrice()<<" $";

    color();
    if(numOption!=0)
    {
        x+=46;
        drawRectangle(x,y,numOption*10+numOption-1,1);
        for(int i=1 ; i<numOption ; i++)
        {
            setCursor(x+11*i,y); cout<<char(194);
            setCursor(x+11*i,y+1); cout<<char(179);
            setCursor(x+11*i,y+2); cout<<char(193);
        }
    }
}

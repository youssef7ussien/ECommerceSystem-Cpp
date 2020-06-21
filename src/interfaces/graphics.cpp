#include "Graphics.h"
#include <iostream>
using namespace std;

void initConsole()
{
//    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
//    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    //HWND hWnd = GetConsoleWindow();
    setConsoleSize(130,35);
    SetConsoleTitle("E-Commerce Management System");
//    MoveWindow(hWnd,50,50,50,50,TRUE);
//    ShowWindow(GetConsoleWindow(),SW_SHOWMAXIMIZED);
    color(LIGHT_GRAY);
	//clearScreen();
}

void setConsoleSize(short width, short height)
{
    _COORD coord={width,height};

    _SMALL_RECT Rect;
    Rect.Top=0;
    Rect.Left=0;
    Rect.Bottom=height-1;
    Rect.Right=width-1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void editCursor(bool visible,float sizeCursor)
{
   CONSOLE_CURSOR_INFO info;
   info.dwSize=sizeCursor;
   info.bVisible=visible;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}

void color(Colors foreground, Colors background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(WORD)((background << 4) | foreground));
}

void setCursor(int x, int y)
{
	COORD cursorPosition;
	cursorPosition.X=x;
	cursorPosition.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cursorPosition);
}

void wait(int milliseconds)
{
	Sleep(milliseconds);
}

void clearLine(int length)
{
    while(length--)
    {
        cout<<" ";
    }
}

void clearMultiLines(int x,int y,int numberLines,int length)
{
	for (int i=0 ; i<numberLines ; i++)
    {
        setCursor(x,i+y); clearLine(length);
    }
}

void drawRectangle(int x, int y, int width, int height,int style)
{
    height+=1;
    width+=2;
    char topLeft='0',topRight='0',bottomLeft='0',bottomRight='0',verticalLine='0',horizontalLine='0';
    switch(style)
    {
        case 1:
            topLeft=char(218);
            topRight=char(191);
            bottomLeft=char(192);
            bottomRight=char(217);
            verticalLine=char(196);
            horizontalLine=char(179);
            break;
        case 2:
            topLeft=char(201);
            topRight=char(187);
            bottomLeft=char(200);
            bottomRight=char(188);
            verticalLine=char(205);
            horizontalLine=char(186);
            break;
    }

    setCursor(x,y);
    cout<<topLeft;
	for(int i=1; i<width-1 ; i++)
        cout<<verticalLine;
    cout<<topRight;

	setCursor(x,y+height);
    cout<<bottomLeft;
	for(int i=1 ; i<width-1 ; i++)
        cout<<verticalLine;
    cout<<bottomRight;

    setCursor(x,y+1);
	for (int i=y+1 ; i<y+height ; i++)
	{
		setCursor(x,i);
		cout<<horizontalLine;
		setCursor(x+width-1,i);
		cout<<horizontalLine;
	}
}

void drawCircle(int xC, int yC, int radius)
{
	double theta, increment, xF, pi=3.14159;
	int x, xN, yN;

	increment=0.8/static_cast<double>(radius);
	for (theta=0; theta<=pi/2; theta += increment)
	{
		xF=radius * cos(theta);
		xN=static_cast<int>(xF*2/1);

		yN=static_cast<int>(radius*sin(theta)+0.5);
		x=xC-xN;
		while(x<=xC+xN)
		{
			setCursor(x, yC-yN); cout<<char(191)<<endl;
			setCursor(x++, yC+yN); cout<<char(191)<<endl;
		}
	}
}

void drawLine(int x1, int y1, int x2, int y2,Colors colorLine)
{
    color(colorLine);
	double deltaX=x1-x2, deltaY=y1-y2;
	if(fabs(deltaX)>fabs(deltaY))
	{
		double slope=deltaY/deltaX;
		for (int i=x1; i<=x2; i++)
        {
            int z=static_cast<int>(y1+slope*(i-x1));
            setCursor(i,z);  cout<<char(196);
        }
	}
	else
	{
		double slope=deltaX/deltaY;
		for (int i=y1; i<=y2; i++)
        {
            int z=static_cast<int>(x1+slope*(i-y1));
            setCursor(z, i);
            cout<<char(179);
        }
	}
	color();
}

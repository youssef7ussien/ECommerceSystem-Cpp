#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <Windows.h>
#include <conio.h>
#include <math.h>

#define KEY_UP          72
#define KEY_DOWN        80
#define KEY_LEFT        75
#define KEY_RIGHT       77
#define KEY_ENTER       13

#define KEY_HOME        71
#define KEY_ESC         27
#define KEY_CENTER      76
#define KEY_END         79

#define KEY_PAGEUP      73
#define KEY_PAGEDOWN    81

#define KEY_INSERT      82
#define KEY_DELETE      83

#define KEY_F1          59
#define KEY_F2          60
#define KEY_F3          61
#define KEY_F4          62
#define KEY_F5          63
#define KEY_F6          64
#define KEY_F7          65
#define KEY_F8          66
#define KEY_F9          67

enum FillStyle {
    SOLID_FILL,
    X_FILL,
    O_FILL,
    LIGHT_FILL,
    MEDIUM_FILL,
    DARK_FILL
};

enum Colors {
    BLACK=0,
    DARK_BLUE,
    DARK_GREEN,
    DARK_CYAN,
    DARK_RED,
    DARK_MAGENTA,
    BROWN,
    LIGHT_GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    WHITE
};

void initConsole();
void setConsoleSize(short, short);
void color(Colors foreground=LIGHT_GRAY, Colors background=BLACK);
void setCursor(int x, int y);
void editCursor(bool ,float sizeCursor=1);
void clearScreen();
void clearLine(int);
void wait(int);
void drawRectangle(int, int, int, int,int style=1);
void drawCircle(int, int, int);
void drawLine(int, int, int, int,Colors colorLine=LIGHT_GRAY);
void setFillStyle(FillStyle);

#endif // GRAPHICS_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include "rectangle.h"

using namespace std;
/*Getting elements of rectangle*/
int Rectangle::GetTop() const
{
    return Top;
}

int Rectangle::GetLeft() const
{
    return Left;
}

int Rectangle::GetRight() const
{
    return Right;
}

int Rectangle::GetBottom() const
{
    return Bottom;
}
/*Setting elements of rectangle*/
void Rectangle::SetTop(int newtop)
{
    Top = newtop;
}
void Rectangle::SetLeft(int newleft)
{
    Left = newleft;
}
void Rectangle::SetBottom(int newbottom)
{
    Bottom = newbottom;
}
void Rectangle::SetRight(int newright)
{
    Right = newright;
}


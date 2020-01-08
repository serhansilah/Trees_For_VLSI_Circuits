#include <string>
#ifndef main_h
#define main_h
using namespace std;
class Rectangle
{
    public:
		Rectangle()//constructor
			:Top(NULL),Left(NULL),Bottom(NULL),Right(NULL)
		{}
    void SetTop(int newtop) ;
    void SetLeft(int newleft) ;
    void SetBottom(int newbottom) ;
    void SetRight(int newright) ;
    int GetTop() const;
    int GetLeft() const;
    int GetRight() const;
    int GetBottom() const;
    
    private:
    int Top; // y coordinate of the upper edge
    int Left; // x coordinate of the left edge
    int Bottom; // y coordinate of the bottom edge
    int Right; // x coordinate of the right edge
};


#endif /* main_h */

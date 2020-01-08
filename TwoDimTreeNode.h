#ifndef TwoDimTreeNode_h
#define TwoDimTreeNode_h
#include "rectangle.h"
#include <vector>
using namespace std;
struct Vertical//vertical vector of a node stores elements of rectangle or rectangles which are intersects with node horizontally
{
    Rectangle r;
};
struct Horizontal // horizontal vector of a node stores elements of rectangle or rectangles which are intersects with node horizontally
{
    Rectangle r;
};
class Tree
{
private:
    class TwoDimTreeNode
    {
    public:
        TwoDimTreeNode()//constructor
        :TopLeft(NULL),TopRight(NULL),BottomLeft(NULL),BottomRight(NULL),Extent()
        {}
    private:
        TwoDimTreeNode *TopLeft;
        TwoDimTreeNode *TopRight;
        TwoDimTreeNode *BottomLeft;
        TwoDimTreeNode *BottomRight;
        Rectangle Extent;
        vector<Rectangle> Vertical, Horizontal;
        friend class Tree;
    };
    TwoDimTreeNode *root;
public:
    Tree();
    void recsearch(int queryx, int queryy);
    void extentinsert(int top,int left,int bottom,int rigth);
    void insert_rectangle(Rectangle r, bool first);
};


#endif /* TwoDimTreeNode_h */

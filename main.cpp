#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "rectangle.h"
#include "TwoDimTreeNode.h"
#include <vector>
#include <stdlib.h>

using namespace std;
struct query//store the input values
{
    int xcoordinate;
    int ycoordinate;
};

void addcoordinate( vector<query> & list, int x , int y)//adding input values to struct
{
    query q;
    q.xcoordinate = x;
    q.ycoordinate = y;
    list.push_back(q);
}
int main() {
    vector<query> list;
    ifstream file;
    int top,left,right,bottom;
    string filename = "rectdb.txt";
    file.open(filename.c_str());
    Tree *head;
	head = new Tree();
    bool first = true;
	Rectangle r;
    string coordinate;
    if(file.fail())
    {
        cout << "File did not open.";
        return 0;
    }
    while(!file.eof() || top != -1)//when top value entered as -1 program stops
    {
        getline(file, coordinate);// reading line by line
        istringstream file(coordinate);
        file >> top >> left >> bottom >> right;
        if(first)//for root of the two dim tree first set the main extent 
        {
            if(top != -1)//after read the file if top entered as -1 need to wait one turn while loop
            {
				r.SetTop(top);
				r.SetLeft(left);
				r.SetRight(right);
				r.SetBottom(bottom);
                head -> insert_rectangle(r,first);
                head -> extentinsert(top,left, bottom,right);
                first = false;//after set the main extent coordinates this boolean value never become true
            }
        }
        else
        {
            if(top != -1)//after read the file if top entered as -1 need to wait one turn while loop
            {
				r.SetTop(top);
				r.SetLeft(left);
				r.SetRight(right);
				r.SetBottom(bottom);
                head -> insert_rectangle(r,first);//inserting rectangle but speacial case for first rectangle
            }
        }
    }
    int x, y;
	cin >> x >> y;
    while(x != -1)
    {
		addcoordinate(list, x, y);//do not take a value query point starts with -1
        cin >> x >> y;
    }
    for(int i= 0;i < list.size();i++)
    {
        head -> recsearch(list[i].xcoordinate, list[i].ycoordinate);//search rectangles which are intersects with query point
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#include "TwoDimTreeNode.h"
#include "rectangle.h"

using namespace std;

struct found//vector of founded vector intersect with query point
{
	int qx, qy, count, r_top, r_bottom, r_right, r_left;
};

void Tree::extentinsert(int top,int left,int bottom,int right)//insert first main rectangle which include twodimtree and all rectangles
{
    root ->Extent.SetBottom(bottom);
    root ->Extent.SetLeft(left);
    root ->Extent.SetRight(right);
    root ->Extent.SetTop(top);
}
void Tree::insert_rectangle(Rectangle r, bool first)
{
    int centx,centy;
    bool added = false;
    TwoDimTreeNode *temp = root;
    TwoDimTreeNode *ptr = root;
    if(first)
    {
        root -> Vertical.push_back(r);//main rectangle pushed vertical vector of root
    }
    centx = (root -> Extent.GetLeft()+ root -> Extent.GetRight())/2; //coordinates of the root located at center
    centy = (root -> Extent.GetBottom()+ root -> Extent.GetTop())/2;
    if(centy <r.GetBottom() && centy >= r.GetTop() && !first)//check horizontal intercestion of root with other rectangles
    {
        root -> Horizontal.push_back(r);
    }
    else if(centx <r.GetRight() && centx >= r.GetLeft() && !first)//check vertical intercestion of root with other rectangles
    {
        root -> Vertical.push_back(r);
    }
	else if(!first)
	{ 
		while (!added)//if the rectangle added a node then the insert function close
		{
			if (centy >= r.GetBottom() && centx >= r.GetRight())//check rectangles position then create node
			{
				ptr = temp;
				if (temp->TopLeft == NULL)//do not create same node again
				{
					temp->TopLeft = new TwoDimTreeNode;
				}
				temp = temp->TopLeft;
				temp->Extent.SetBottom(centy);
				temp->Extent.SetRight(centx);
				temp->Extent.SetLeft(ptr->Extent.GetLeft());
				temp->Extent.SetTop(ptr->Extent.GetTop());
				centx = (temp->Extent.GetLeft() + temp->Extent.GetRight()) / 2;//coordinates of the node 
				centy = (temp->Extent.GetBottom() + temp->Extent.GetTop()) / 2;
				if ( temp->Extent.GetBottom() < 1 || temp->Extent.GetTop() < 1)//check that extent of rectangle can not be less than 1
				{
					added = true;
					//delete ptr;
					delete temp;
				}
				else
				{
					if (centy < r.GetBottom() && centy >= r.GetTop())//push horizontal vector of node if it is correct
					{
						temp->Horizontal.push_back(r);
						added = true;
					}
					else if (centx < r.GetRight() && centx >= r.GetLeft())//push vertical vector of node if it is correct
					{
						temp->Vertical.push_back(r);
						added = true;
					}
				}
			}
			else if (centy >= r.GetBottom() && centx < r.GetRight())//check rectangles position then create node
			{
				ptr = temp;
				if (temp->TopRight == NULL)
				{
					temp->TopRight = new TwoDimTreeNode;
				}
				temp = temp->TopRight;
				temp->Extent.SetBottom(centy);
				temp->Extent.SetRight(ptr->Extent.GetRight());
				temp->Extent.SetLeft(centx + 1);
				temp->Extent.SetTop(ptr->Extent.GetTop());
				centx = (temp->Extent.GetLeft() + temp->Extent.GetRight()) / 2;
				centy = (temp->Extent.GetBottom() + temp->Extent.GetTop()) / 2;
				if (centy < 1 || centx < 1)//check that extent of rectangle can not be less than 1
				{
					added = true;
					//delete ptr;
					delete temp;
				}
				else
				{
					if (centy < r.GetBottom() && centy >= r.GetTop())
					{
						temp->Horizontal.push_back(r);
						added = true;
					}
					else if (centx < r.GetRight() && centx >= r.GetLeft())
					{
						temp->Vertical.push_back(r);
						added = true;
					}
				}

			}
			else if (centy < r.GetBottom() && centx >= r.GetRight())//check rectangles position then create node
			{
				ptr = temp;
				if (temp->BottomLeft == NULL)
				{
					temp->BottomLeft = new TwoDimTreeNode;
				}
				temp = temp->BottomLeft;
				temp->Extent.SetBottom(ptr->Extent.GetBottom());
				temp->Extent.SetRight(centx);
				temp->Extent.SetLeft(ptr->Extent.GetLeft());
				temp->Extent.SetTop(centy + 1);
				centx = (temp->Extent.GetLeft() + temp->Extent.GetRight()) / 2;
				centy = (temp->Extent.GetBottom() + temp->Extent.GetTop()) / 2;
				if (centy < 1 || centx < 1)//check that extent of rectangle can not be less than 1
				{
					added = true;
					//delete ptr;
					delete temp;
				}
				else
				{
					if (centy < r.GetBottom() && centy >= r.GetTop())
					{
						temp->Horizontal.push_back(r);
						added = true;
					}
					else if (centx < r.GetRight() && centx >= r.GetLeft())
					{
						temp->Vertical.push_back(r);
						added = true;
					}

				}

			}
			else if (centy < r.GetBottom() && centx < r.GetRight())//check rectangles position then create node
			{
				ptr = temp;
				if (temp->BottomRight == NULL)
				{
					temp->BottomRight = new TwoDimTreeNode;
				}
				temp = temp->BottomRight;
				temp->Extent.SetBottom(ptr->Extent.GetBottom());
				temp->Extent.SetRight(ptr->Extent.GetRight());
				temp->Extent.SetLeft(centx + 1);
				temp->Extent.SetTop(centy + 1);
				centx = (temp->Extent.GetLeft() + temp->Extent.GetRight()) / 2;
				centy = (temp->Extent.GetBottom() + temp->Extent.GetTop()) / 2;
				if (centy < 1 || centx < 1)//check that extent of rectangle can not be less than 1
				{
					added = true;
					//delete ptr;
					delete temp;
				}
				else
				{
					if (centy < r.GetBottom() && centy >= r.GetTop())
					{
						temp->Horizontal.push_back(r);
						added = true;
					}
					else if (centx < r.GetRight() && centx >= r.GetLeft())
					{
						temp->Vertical.push_back(r);
						added = true;
					}
				}

			}
		}
	}
  
}
Tree::Tree()
{
    root = new TwoDimTreeNode;    //creating root of the tree
}
void print(vector<found> & f)
{
    for(int t = 0; t < f.size();t++)
    {
        if(f[t].count == 0)//if query point have not got intersection
        {
            cout << f[t].qx << " " << f[t].qy<<endl;
            cout << f[t].count << endl;
        }
        else
        {
            if(t== 0)//print the first then check others
            {
                cout << f[t].qx << " " << f[t].qy<<endl;
                cout << f[t].count << endl;
                cout << f[t].r_top << " " << f[t].r_left << " " << f[t].r_bottom << " " << f[t].r_right << endl;
            }
			/*check that same query point if it has got more than one rectangle or not
			because do not want to print query point and count more than once
			*/
            else if(f[t-1].qx == f[t].qx && f[t-1].qy == f[t].qy)
            {
                cout << f[t].r_top << " " << f[t].r_left << " " << f[t].r_bottom << " " << f[t].r_right << endl;
            }
            else if(t >1)// if it is change continue to print other query point
            {
                cout << f[t].qx << " " << f[t].qy<<endl;
                cout << f[t].count << endl;
                cout << f[t].r_top << " " << f[t].r_left << " " << f[t].r_bottom << " " << f[t].r_right << endl;
            }
        }
        
    }
	f.clear();//clear the query point intersection to do not print again for other query points

}
void Tree::recsearch(int queryx, int queryy)
{
    vector<found> found;
    struct found f;
    int centx,centy;
    TwoDimTreeNode *temp = root;
    int count = 0;
	while (temp != NULL)//search intersection of query point and rectangles by looking nodes vectors
	{
		centx = (temp->Extent.GetLeft() + temp->Extent.GetRight()) / 2;
		centy = (temp->Extent.GetBottom() + temp->Extent.GetTop()) / 2;
		for(int i = 0;i < temp->Horizontal.size();i++)//check inside horizontal vector or not
		{
			if (temp->Horizontal[i].GetTop() <= queryy&& queryy < temp->Horizontal[i].GetBottom() && temp->Horizontal[i].GetLeft() <= queryx && queryx < temp->Horizontal[i].GetRight())
			{
				count++;
				f.qx = queryx;
				f.qy = queryy;
				f.r_top = temp->Horizontal[i].GetTop();
				f.r_left = temp->Horizontal[i].GetLeft();
				f.r_right = temp->Horizontal[i].GetRight();
				f.r_bottom = temp->Horizontal[i].GetBottom();
				found.push_back(f);
			}
		}
        for(int i = 0; i< temp-> Vertical.size();i++)//check inside vertical vector or not
        {   
            if(temp -> Vertical[i].GetTop() <= queryy && queryy < temp ->Vertical[i].GetBottom() && temp -> Vertical[i].GetLeft() <= queryx && queryx< temp -> Vertical[i].GetRight())
            {
                if(temp == root && i == 0);
                else
                {
                    count++;
                    f.qx =queryx;
                    f.qy = queryy;
                    f.r_top = temp -> Vertical[i].GetTop();
                    f.r_left= temp -> Vertical[i].GetLeft();
                    f.r_right=temp -> Vertical[i].GetRight();
                    f.r_bottom= temp ->Vertical[i].GetBottom();
                    found.push_back(f);
                }
            }
        }
		//go to other nodes which is close to query point and that query point inside that nodes extent
        if(queryx >= centx+1 && queryy <= centy)
        {
            temp = temp->TopRight;
        }
        else if(queryx <= centx && queryy <= centy)
        {
            temp = temp -> TopLeft;
        }
        else if(queryy >= centy +1 && queryx <=centx)
        {
            temp = temp -> BottomLeft;
        }
        else if (queryy >= centy +1 && queryx >= centx+1)
        {
            temp = temp->BottomRight;
        }
    }
	if (count == 0)//if query point never intersects
	{
		f.qx = queryx;
		f.qy = queryy;
		f.r_top = 0;
		f.r_left = 0;
		f.r_right = 0;
		f.r_bottom =0;
		found.push_back(f);
	}
	for (int i = 0; i < found.size(); i++)//after all rectangles counted add count value to the member of vectors
	{
		found[i].count = count;
	}
    print(found);
}

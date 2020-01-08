Modified Tree

We will implement a slightly more complex version of binary search
trees. Binary search trees typically work on
one dimensional key spaces.
The trees that we will work on let us search on
two-dimensional spaces and extensions to higher dimensional spaces should be obvious. 
These kind of trees are very useful in many graphics applications and in computer aided design tools for
automated design of VLSI (very large scale integration) circuits. 
Instead of each node having at most 2 children, in such trees, nodes have at most 4 children. For reasons that
will be clear in a moment, we will call these children as
TopLeft, TopRight, BottomLeft and BottomRight. 
Before we go on any further, let us briefly discuss how you will use these trees.
Cartesian geometry, the coordinate system in this representation is such that,
as you go towards right and bottom, the x and y coordinates (respectively) increase, 
that is, for a rectangle, Bottom > Top and Right > Left. 
A list of such rectangles can be trivially represented using the LinkedList class.

A point (x, y), on the Cartesian plane is considered to be inside a rectangle object
R(or intersects R), if R.Left ≤ x < R.Right and R.Top ≤ y < R.Bottom, that is, the points on
the right and bottom boundaries of the rectangle are not considered to be in the rectangle.
Given such a point, our tree data structure will enable us to find (hopefully in a very
fast way) all rectangles that contain that point. One can obviously do this by keeping all
rectangles in a linked list and searching through the list by checking if the point is inside
a rectangle or not, but when you have 1,000,000 or 50,000,000 rectangles, that will not be very efficient.

The trees that you will design organize two-dimensional information in the following way:
• You will assume that each such tree covers a portion of the Cartesian plane and that this portion is fixed. 
You will thus assume that the region covered by the tree is represented by some suitable (large) rectangle. 
Call this rectangle Extent.

• The center of the tree rectangle is located at the center point whose x coordinate is – (Extent.Left+Extent.Right)/2
and whose y coordinate is – (Extent.Top+Extent.Bottom)/2 where the / is interpreted as the integer division operator in C++.

• Note that, this center defines four additional smaller rectangles (called quadrants) at the top left, top right, bottom left
and bottom right of the center point. So, if you are given a point (x, y) you only need to find which quadrant the point falls,
and then just search the rectangles that you know (may) overlap with that quadrant, not all rectangles. 
Note also that this can be extended recursively to smaller quadrants within a quadrant until a minimum rectangle size is reached. 

The two dimensional tree class will just contain a single private entry that points to a root node of the class 
TwoDimTreeNode just like the binary search tree definition we discussed in the class. 
The rectangle Extent defines the region covered by the tree. Vertical and Horizontal are two linked lists of rectangles. 
Vertical keeps the list of rectangles which intersect the vertical line x = (Extent.Left + Extent.Right)/2 and 
Horizontal keeps the list of rectangles which intersect the horizontal line y = (Extent.Top+Extent.Bottom)/2. 
If a rectangle intersects both lines, then it is put on only one of these lists and not two. 

If a rectangle does not intersect any of these lines then, it is either in the tree pointed by TopLeft which covers the rectangular extent with
Top = Extent.Top   Left = Extent.Left  Bottom = (Extent.Top + Extent.Bottom)/2   Right = (Extent.Left + Extent.Right)/2
or in one of the other 3 regions (pointed to by TopRight, BottomLeft, BottomRight) whose extents can be defined similarly. 
Thus, it is recursively inserted to the subtree of the relevant quadrant unless the width or the length of the extent is 1 
so that it can not be subdivided any further. The important point to note is that a given rectangle is inserted to 
either the Horizontal or the Vertical lists associated with the subtree whose center lines it intersects. 
Note also that the extents of the children subtrees do not intersect either of the center lines. 
An example can be of help here. Suppose the tree covers the extent
Top = 0, Left = 0, Bottom = 4 and Right = 5. Then,
• the TopLeft quadrant of this extent is defined by Top = 0, Left = 0, Bottom = 2 and Right = 2.
• the TopRight quadrant of this extent is defined by Top = 0, Left = 3, Bottom = 2 and Right = 5.
• the BottomLeft quadrant of this extent is defined by Top = 3, Left = 0, Bottom = 4 and Right = 2.
• and the BottomRight quadrant of this extent is defined by Top = 3, Left = 3, Bottom = 4 and Right = 5.
Also note that areas of the quadrants need not be equal but they are close.
To search for the rectangles that a point (x, y) intersects with, you first checks if the point falls in any of rectangles
on the Vertical and Horizontal lists of the root node. If so, these rectangles are output (or inserted to a result list of 
rectangles) and search continues recursively with the subtree covering the quadrant the point falls into. 
(No additional search is needed if the point falls on the center lines of the tree.) 

In order to simplify certain matters, we will assume that the data for the rectangle database will be in a 
file called rectdb.txt

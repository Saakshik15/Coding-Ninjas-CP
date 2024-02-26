/*
Let's say we have two points a(x1, y1) and b(x2, y2) on a 2D plane

Now, slope of the line for these points is defined as:

slope(m) = (y2- y1) / (x2- x1)

The higher the slope is, the steeper the line is.

For eg, we have two lines as l1 and l2 having slope m1 and m2.
Now, if m1>m2, then the line l1 is steeper than l2.

If the lines l1 and l2 have equal slope, m1= m2 then they are collinear lines.
*/



/*
Clockwise orientation:
For clockwise orientation of lines l1 and l2, m1> m2, that means l1 is steeper than l2.
Thus, we can derive,

(y2- y1)/(x2- x1) > (y3- y2)/(x3- x2)
(y2- y1)(x3- x2) > (y3- y2)(x2- x1)
(y2- y1)(x3- x2) - (y3- y2)/(x2- x1) > 0
If points a,b,c are clockwise, then this condition will hold true.


Collinear points:
For collinear points, the exact xpression will be avaluated to 0:
(y2- y1)(x3- x2) - (y3- y2)/(x2- x1) = 0


Anticlockwise orientation:
(y2- y1)(x3- x2) - (y3- y2)/(x2- x1) < 0
If points a,b,c are anticlockwise, then this condition will be true.
*/

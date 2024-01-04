EXTENDED EUCLIDEAN ALGORITHM EXPLAINATION

Suppose 2x + 3y = 5 is a linear equation.
This equation may have a solution.

But, this linear equation is called an LDE (Linear Diophantine Equation) only 
if the solution to this euqation is an integer.

If ax + by = c is an equation,
The solution for the eqation may or may not exist.
The solution exists if and only if c % g = 0 (c is divisible by gcd(a,b))

Example, 

If we have to find out the solution for the LDE : 10x + 6y = 8, 
then, we will actually first find out the solution to the equation : 10x + 6y = 2, bcs 2 is a gcd of 10 and 6
so eventually we will utilize the solution of the second quation to find the solution for the first equation.

now, for the equation: 10x + 6y = 2

a    b    x    y    eqn
10   6              10x + 6y = 2
6    4              6x + 4y = 2
4    2              4x + 2y = 2
2    0              2x + 0y = 2
  
                    (x=1, y=0) for final solution


if we consider the last level as 
bx1 + (a%b) y1 = g whose solution is x1, y1 which we have found out at the end,

ans upper level as 
ax + by = g //eqn 1
  whose solution is x,y and we have to calculate it utilizing the ans of the lower level,

we can see a%b is actually a- floor(a/b) *b 
  (consider floor(a/b) = [a/b])

replacing by this in the last level eqn, which is bx + (a%b)y = g, we get

bx1 + (a- [a/b]*b) y1 = g
bx1 + ay1 - [a/b]*b*y1 = g
ay1 + b (x1 - [a/b]*y1) = g //eqn 2

comparing eqn 1 and eqn 2, 
comparing ax from eqn 1 and ay1 from eqn 2, 
  thus we get x = y1

comparing by from eqn 1 and b (x1 - [a/b]*y1) from eqn 2,
  we get y = x1 - [a/b]*y1

thus, in short,
  x = y1 and y = x1 - [a/b]*y1

  where x and y are upper levels and x1 and y1 are the lower levels whose answers are known.

thus filling up the table using the obtained formula:

a    b    x    y    eqn
10   6   -1    2    10x + 6y = 2  //so, x= -1 and y= 2 is the solution to 10x + 6y = 2
6    4    1   -1    6x + 4y = 2
4    2    0    1    4x + 2y = 2
2    0    1    0    2x + 0y = 2
  
we have found the solution to 10x + 6y = 2, utilizing this we have to find the solution for 10x + 6y = 8.
thus, we have to multiply the solution by c/gcd(a,b) that is, 8/2 = 4
that is, x= -4 and y= 8 is the answer to the equation.



//formula: C(n+r-1, r-1) or C(n+r-1, n)

/*
Stars and bars:

Imagine you have N identical objects (which we represent as stars) that you want to distribute into K distinct groups, 
such that each group can have 0 to N number of elements. The Stars and Bars theorem states that there are C(N+K-1, K-1) 
ways to do this, where C denotes the binomial coefficient.

The stars and bars technique, also known as "balls and bars" or "dots and dividers," is a way to count 
that in how many different ways you can arrange identical objects into distinct groups.

In case where group cannot have 0 objects:
Imagine you have N identical objects (which we represent as stars) that you want to distribute into K distinct groups, 
such that each group should have at least 1 object. The Stars and Bars theorem states that there are C(N-1, K-1) ways 
to do this, where C denotes the binomial coefficient.
*/


/*
Example:

If we have 5 identical objects and want to distribute them among 3 groups, int how many ways is it possible to do this?

Draw 3 boxes (groups) and 5 stars (objects) in between: * | ** | **
Each arrangement of stars and bars represents a way to distribute the cookies. 

For example, 
** | ** | * means the first group gets 2 objects, the second gets 2, and the third gets 1.

Use the formula:  C(n+r-1, r-1) or C(n+r-1, n)

(5 + 3 - 1 choose 3 - 1) = (7 choose 2) = 21
Therefore, there are 21 different ways to distribute the objects among the 3 groups.
*/

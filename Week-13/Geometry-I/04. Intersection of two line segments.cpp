/*

To check if two lines are intersectiong or not,
we can run the following tests on the given line segments:

suppose, the given co-ordinates are A(p1, q1) and B(p2, q2)
then,

1st test (if they are not collinear)
if orientation(p1, q1, p2) != orientation(p1, q1, p2) & orientation(p2, q2, q1) != orientation(p2, q2, q1) 
  return true

2nd test (if given lines are collinear)
if orientation(p1, q1, p2)== 0 & orientation(p2, q2, p1)== 0 : 
  check if their x and y projections overlap
    return true

if not either of these cases
  return false
  
*/

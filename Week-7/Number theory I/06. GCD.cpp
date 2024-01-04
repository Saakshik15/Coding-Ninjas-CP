zDeriving GCD

Some facts about GCD:

1. GCD of any number and 0 is the number itself. 
  GCD(a, 0) = a
  
2. GCD of two numbers does not change if we replace one of them by their difference.
  GCD(a, b) = GCD(a-b, b) = GCD(a, b-a);

Now, using these facts, suppose we have to find the GCD of (105, 25) then 
by rule 2, :
(105, 25)                          //1
(105-25, 25) -> (80, 25)
(80-25, 25)  -> (55, 25)
(55-25, 25)  -> (30, 25)
(30-25, 25)  -> (5, 25) -> (25, 5) //2
(25-5, 5)    -> (20, 5)
(20-5, 5)    -> (15, 5)
(15, 5)      -> (10, 5)
(10, 5)      -> (5,5)
(5-5, 5)     -> (0, 5)  -> (5, 0)  //3
  
using rule 1, GCD is 5 since GCD(a,0) = a

but instead of substracting at each step which may increase the TC, we can observe a pattern here in //1, 2, 3

(105, 25) -> ( 25,   5  ) ->  ( 5,   0)
( x   y )    ( y   z= x% y)   ( z, y% z)

  



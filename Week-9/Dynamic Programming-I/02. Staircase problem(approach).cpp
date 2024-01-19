/*
The problem statement:

bob is standing at the 0th floor, he has to reach the 1st floor by taking n steps on the staircase.
He can take 1 step at a time or 2 or 3.
In how many ways can he reach the first floor?
*/


/*
Let's say there are n steps.
The number of ways bob can go up a stair is then 
f(p) = f(p+1) + f(p+2) + f(p+3) from the current step which is the nth step.

The base case, or at the last step,
let's say bob is standing on the nth step now, which is the last step:
now, in this case,
f(n) = 1
f(n+1)= 0 (number of ways bob can reach up from nth stair will be 0)
f(n+2)= 0; (number of ways in which bob can reach up the nth stair will be 0 in this case too)

recursion will take place in the following way for input f(4):

                          f(0)
                     /       |   \
                    f(1)    f(2)  f(3)
                 /   |  \
             f(2)   f(3) f(4)
          /   |  \
      f(3)  f(4) f(5)
    /  |  \
f(4) f(5) f(6)

f(4), now, as it n, then the base case will be executed. So, the number of ways for bob to climb up is 
f(4) = 1,
f(5) = 0,
f(6) = 0

In this way, we will calculate f(n).
Along with calculating f(step) we will be also memoizing it to the array.
*/

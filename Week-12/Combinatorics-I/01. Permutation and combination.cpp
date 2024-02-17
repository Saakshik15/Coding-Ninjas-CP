/*
Permutation:

The different ways of arranging a set of objects into a sequential order is termed as permutation.

There are two types of permutations:

Where repitition is allowed: 
eg. combination lock where digits could be repeated.
Formula: n(P)r = n^r
where, n= total no of objects
       r= no of ojects selected

Where repitition is not allowd: 
eg. In how many ways can 8 runners come in 1st, 2nd and 3rd place?
(since all runners will be at different positions, repitition is not possible.)
Formula: n(P)r =  n! / (n-r)!
where, n= total no of objects
       r= no of objects selected
*/


/*
Combination:

It is a way of selecting elements from a set in a way such that the order of selection does not matter.

There are two types of combinations:

When repitition is not allowed:
selecting three random lottery tickets from six lottery tickets 
(here, the order of selection does not matter, also tickets should not be repeated)
Formula: n(C)r = n(P)r/n! = n!/(n-r)!X r!
where, n= total no of objects from the set
       r= no of objects selected from the set

when repitition is allowed:
eg. selecting 3 ice creams from 8 flavours of ice cream
(here, the person can also select same flavour twice or thrice)
Formula: n(C)r = (n+r-1)! / (n-1)! X r!
where, n= total no of objects in the set
       r= no of selected objects from the set
*/


/*
_________________________________________________________________________________
|PERMUTATION                          | COMBINATION                              |
|_____________________________________|__________________________________________|
|1. Denotes the arrangement of objects|1. does not denote arrangement of objects |
|2. order matters                     |2. order does not matter                  |
|3. used for lists                    |3. used for groups                        | 
|_____________________________________|__________________________________________|
*/


//tip: while permutation: "arrange", combination: "choose", "select"

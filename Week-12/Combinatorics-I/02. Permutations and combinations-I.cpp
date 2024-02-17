//Function to evaluate Permutation given n,r:

P(n,r){
  res=1;

  loop: i=n to n-r+1, i--
    res= res*i

  return res
}

//loop till n-r+1 beacuse, formula = n!/ (n-r)!
//eg, if n=6 and r=3, then P= 6*5*4 (n=6 and 4= n-r+1) 


/*
Relation between permutation and combination:

Since we know in permutation order matters which is not the case in combinations,
so logically for each combination of r objects, we have r! permutations for the same chosen arranged objects.
eg. if we have letters to be arranged as (1,2,3) then for permutations, these letters would be arranged in 
3! ways, that is total 6 ways.

Thus, the relation between permutation and combinations can be stated as:

n(P)r = N(C)r X r!

thus, n(C)r = n(P)r /r!

in conclusion, n(C)r is: 
n(C)r = n!/ (n-r)! x r!


*/

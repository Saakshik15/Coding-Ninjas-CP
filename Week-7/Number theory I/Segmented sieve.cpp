/*
There are certain problems for finding prime numbers which cannot be solved with the help of normal sieve.
These can be finding out sieve in the given range, (L,R), given that L ans R can be as large as 10^10.
As we cannot create an array of size 10^10, it is not possible to solve this problem using normal sieve.

There would be given an equally important condition, which is R-L <= 10^5.
We can easily create an array of size 10^5.

Segmented sieve is thus applying the sieve algorithm on a given segment.

We have to perform certain steps for that:

(We will create an array of range from (L,R) and assign all numbers as true at first.)
Step 1: Find all primes upto sqrt(R) using normal sieve.

Step 2: Use the primes you have found to cross their multiples present in this range (L,R) ->
  Here, to find the first number divisible by the primes, we will check by two ways:
    1. If (num(L) is divisible by prime(P)) then (L/P)* P
    2. Else if (num(N) is not divisible by prime(P)) then (L/P)*P +P
    
Step 3: The remaining numbers after crossing out the multiples of prime numbers are the prime numbers in the range (L,R)
      To find the indexes given the number are different, we can find index of the number simply by (j-L) = index  
*/


//IMPLEMENTATION CODE

#include <bits/stdc++.h>
using namespace std;

//sieve for finding prime numbers -> sqrt(L) by normal sieve
vector<int> sieve(int n){
    
    vector<int> primes;
    bool arr[n+1];
    
    for(int i=1; i<=n; i++) arr[i] = true;
    arr[1] =false;
    
    for(int i=1; i<=n; i++) {
        if(arr[i]==true){
            for(int j= i*i; j<=n; j+=i) arr[j]=false;
        }
    }
    for(int i=1; i<=n; i++){
        if(arr[i] ==true) primes.push_back(i);
    }
    return primes;
}

int main(){
    int L, R;
    cin>>L>>R;
    
    //segmented sieve
    bool arr[R-L+1];
    for(int i=L; i<=R; i++) arr[i-L]=true;
    
    //step 1
    vector<int> primes= sieve(sqrt(R));
    
    //step 2 
    for(int p:primes){
        int start= (L/p) *p;
        if(start% p != 0) start+= p;
        
        for(int j=start; j<=R; j+=p)
            arr[j-L]=false;
    }
    
    //step 3
    //printing primes between L to R
    for(int i=L; i<=R; i++) {
        if(arr[i-L]) cout<<i<<" ";
    }
}



//

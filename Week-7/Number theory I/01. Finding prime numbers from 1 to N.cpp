Finding prime numbers from 1 to N:

1. Brute force method:

To find all the prime numbers from 1 to N, by brute force method, we will run a loop from 1 to N and for each number n, divide that
by numbers from 1 to the number itself(n), if the number is divsible by any other number except one and itself, it is not prime, 
otherwise it is prime.

//code:

#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

void primes(int n){
    for(int i=2; i<=n; i++){
        if(isPrime(i)) cout<<i<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    
    primes(n);
}



2. Optimized method:

In the optimized method, to find the number n is a prime or not, instead of running a loop from 1 till n, 
we will run a loop from 1 till sqrt(n) , since if there are no divisors in the first half, there won't be any
divisors present in the second half as well, since the divisors form a pair with their counterparts on the second half.
If the number is a perfect square like 16, we will get an extra pair like (4,4) which will lie at the centre, 
which is a special case.

//code:

#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i*i <= n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

int main(){

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        if(isPrime(i)) cout<<i<<" ";
        
    }
    return 0;
}

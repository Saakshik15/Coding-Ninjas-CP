Observation: 

If a number n is a prime number, than the multiples of that prime number clearly cannot be prime numbers as they already have divisor.
This is the overall idea to eliminate all the multiples of a prime number.

Thus, the overall idea is having two loops to find out the prime numbers,
the first of which will run from 1 till N and the second one will eliminate all the multiples of the numbers which are prime.

loop of i: finds all the prime numbers
loop of j: (inner) crosses out all the multiples of prime numbers

Now, there is another observation which plays an important role:

suppose, we have to find primes from 1 to 50

so, int the first iteration,
1. the first loop will run from 2, and since it is a prime, loop of j crosses out all multiples of 2.
  The first multiple which is crossed out for 2 is :4
2. In the second iteration, since 3 is not crossed out by j loop of prev iteration, we will check if its prime and cross all its multiples.
  The first multiple of 3 we will cross out is: 9
.
.
. Similarly, not considering those numbers which are crossed out we will cross the numbers out and for each prime, the first numbers
  we will be able to cross out will be:
  2 -> 4,
  3 -> 9,
  5 -> 25, (next prime after 3)
  7 -> 49
  till we reach 11, we wont be able to cross out anything, that is because we are finding primes only for 1 to 50 and sq of 11 is 121.
  .
  .
  Thus, we will stop at the number for which we are not able to cross out anything, and the all the rest of the numbers
  which are not crossed out are naturally prime numbers we are looking for.
  because the first number that won't be able to cut out anything will be whose sq is beyond N.
  basically, a number whose sq, root is greater than N.

  so, instead of running a loop for i from 2 till N, we will run a loop only from 2 to sqrt(N).
  Here, sqrt(50) is 7.07 something so we will run a loop from 2 to 7 only.


//Implementation code:

#include <iostream>
using namespace std;

const int n = 100000;
bool prime[n + 1];

void sieve() {
	
    for (int i = 0; i <= n; i++) 
        prime[i] = true;
    prime[1] = false;
                                      
                                      
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {
    	      for (int j = i * i; j <= n; j += i) prime[j] = false;
        }
		}
}

int main() {
    int q;
    sieve();

    cout << "Enter the number of queries: ";
    cin >> q;

    while (q--) {
        int m;
        cout << "Enter a number: ";
        cin >> m;
							  
        if (m <= n){
        	if(prime[m] == true)
            	cout << m << " is a prime number\n";
        	else
            	cout << m << " is not a prime number\n";
		}
		else
			cout<<"The number exceeds the limit\n";	
    }
    return 0;
}

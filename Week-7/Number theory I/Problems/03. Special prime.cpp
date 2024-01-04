/*
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    bool isPrime[n+2];

    memset(isPrime,true, sizeof(isPrime));
    vector<int> primeList;

    for(int i=2; i<=n; i++){
        if(isPrime[i]) {
            for(int j=2; j*i<n+1; j++) isPrime[i*j]=false;
        }
    }

    for(int i=2; i<=n; i++){
        if(isPrime[i]) primeList.push_back(i);
        
    }

    int count =0;
    for(int i=1; i<primeList.size(); i++){
        int a= primeList[i] + primeList[i-1]+1 ;

        if(a<=n && isPrime[a]) count++;
        
    }
    cout<<count<<endl;
}

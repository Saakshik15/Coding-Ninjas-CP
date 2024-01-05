/*
Problem Statement:

Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a 
prime divisor of another flower they needed to be of a different colour.
As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
*/

//code:


#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> primes;
    bool arr[n + 1];
    
    for (int i = 0; i <= n; i++) 
        arr[i] = true;
    
    arr[0] = arr[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (arr[i]) {
            for (int j = i * i; j <= n; j += i) {
                arr[j] = false;
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        if (arr[i]) 
            primes.push_back(i);
        else
            primes.push_back(0);
    }
    
    return primes;
}

int main(){
    
    int n;
    cin>>n;

    if(n==1) cout<<1<<"\n"<<1;
    if(n==2) cout<<1<<"\n"<<2;

    vector<int> prime = sieve(n+1);

    int p=0,c=0;

    for(int i=2; i<=n+1; i++){
        if(prime[i]) p++;
        else c++;
    }

    cout<<2<<"\n";
    cout<< min(p,c)<<" "<<max(p,c);

    return 0;
}

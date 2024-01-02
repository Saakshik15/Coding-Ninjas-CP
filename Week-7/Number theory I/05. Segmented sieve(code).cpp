#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fr(i,a,b) for(int i=a; i<b; i++)
#define loop(x,n) for(int x=0; x<n; ++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

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
    
    for (int i = 2; i <= n; i++) {
        if (arr[i]) 
            primes.push_back(i);
    }
    
    return primes;
}

void segSieve(){
	int L, R;
    cin >> L >> R;
    
    bool arr[R - L + 1];
    for (int i = 0; i <= R - L; i++) 
        arr[i] = true;
    
    vector<int> primes = sieve(sqrt(R)); // Generating primes up to sqrt(R)
    
    for (int p : primes) {
        int start = (L / p) * p;
        if (start < L)
            start += p;
        
        for (int j = max(start, p * p); j <= R; j += p) {
            arr[j - L] = false;
        }
    }
    
    for (int i = L; i <= R; i++) {
        if (i >= 2 && arr[i - L]) {
            cout << i << " ";
        }
    }
    cout<<"\n";
}

int main() {
	fast_io;
    cout<<fixed;
    cout<< setprecision(10);
//  precal();
    int t=1;
    cin >>t;
    for(int i=1; i<=t; i++){
      //cout<< "Case #" << i << ": ";
    segSieve();
  }
    
    return 0;
}

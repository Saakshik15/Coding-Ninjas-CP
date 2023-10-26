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

void precal(){

}

void solve() {
  
  int n,k;
  cin>>n>>k;
  ll maxi = INT_MIN;
  vector<ll> a(n);
  
  loop(i,n) cin>>a[i];

  if(k==0 || k>n){
    cout << "Invalid Input!";
    return;
  }

  ll curr_total =0;
  loop(i,n){
    if(i<k) curr_total +=a[i];
    if(i==k-1) maxi= max(maxi, curr_total);
    else if(i>=k){
      curr_total += a[i];
      curr_total -= a[i-k];
      maxi = max(maxi, curr_total);
    }
  }
  cout<< maxi<<endl;
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  int t=1;
  cin >>t;
  for(int i=1; i<=t; i++){
    cout<< "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}

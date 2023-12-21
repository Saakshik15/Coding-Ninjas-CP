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

bool check(vector<int> barn, int k, int mid){
  int total= 1;
  int last=0;
  int n= barn.size();

  for(int i=1; i<n; i++){
    if(barn[i] - barn[last] >= mid){
      total++;
      last=i;
    }
    if(total>=k) return true;
  }
  return false;
}

void solve() {
  //taking the input
  int n,k;
  cin>>n>>k;
  vector<int> barn(n);
  loop(i,n) cin>> barn[i];
  sort(barn.begin(), barn.end());

  //binary search
  int l=1, r=1e9+5;
  int ans= 1e9+5;

  while(l<=r){
      int mid= l+(r-l)/2;
    if(check(barn, k, mid)==true) {
      ans=mid;
      l= mid+1;
    }else{
      r= mid-1;
    }
  }
  cout<<ans<<"\n";
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  int t=1;
  // cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }

  return 0;
}

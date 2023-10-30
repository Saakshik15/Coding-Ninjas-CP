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

bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second<b.second;
}

void solve() {
  int n;
  cin>>n;

  vector<pair<int,int>> a(n);
  loop(i,n) cin>>a[i].first>>a[i].second;

  sort(all(a),cmp);

  int total=1, last=0;

  loop(i,n){
    if(a[i].first >= a[last].second){
      total++;
      last=i;
    }
  }
  cout<<total;
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  int t=1;
  //cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }

  return 0;
}

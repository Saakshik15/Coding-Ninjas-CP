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

bool cmp(pair<int,int> &a, pair<int,int> &b){
  if(a.second>b.second) return true;
  else if(a.second == b.second) {
    return (a.first < b.first);
  }
  return false;
}

void solve() {
  int n,k;
  cin>>n>>k;

  vector<pair<int,int>>items(n);

  //first is mass and second is value
  loop(i,n) cin>> items[i].first >> items[i].second;

  vector<int>bags(k);
  loop(i,k) cin>>bags[i];

  multiset<int> ms;
   for(auto i: bags) ms.insert(i);

  sort(all(items), cmp);

  ll total=0;
  loop(i,n){
    if(bags.empty()) break;

    auto itr = ms.lower_bound(items[i].first);
    if(itr == ms.end()) continue;
    total+= items[i].second;
    ms.erase(itr);
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

/*
Problem link : 
https://codeforces.com/problemset/problem/799/B
*/

//code:

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
	int n;
	cin >> n;
	vector<int> p(n), a(n), b(n);
	
	for(int i=0; i<n; i++) cin>>p[i];
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];
	
	set<int> s[4];
	
	for(int i=0; i<n; i++){
		s[a[i]].insert(p[i]);
		s[b[i]].insert(p[i]);
	}
	
	int m;
	cin>>m;
	
	for(int i=0; i<m; i++){
		int col, price=0;
		cin>>col;
		price = *s[col].begin();
		for(int j=1; j<=3; j++) s[j].erase(price);
		if(price) cout<<price<<" ";
		else cout<<-1<<" ";
	}
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  
  int t=1;
//  cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}

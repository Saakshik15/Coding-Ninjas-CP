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
	int a;
	cin>>a;
	
	vector<int> ans(a);
	loop(i,a) cin>>ans[i];
	
	int o=0, e=0;
	loop(i,a){
		if((ans[i] &1) !=1) e++;
		else o++;
	}
	
	if(e!=0 && o!=0){
		sort(ans.begin(), ans.end());
		loop(i,a) cout<<ans[i]<<" ";
	}else{
		loop(i,a) cout<<ans[i]<<" ";
	}
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






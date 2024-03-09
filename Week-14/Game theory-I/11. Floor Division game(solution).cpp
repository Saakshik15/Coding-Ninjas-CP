//pattern observed in the Grundy numbers:
//G(n) = G(n/12)  if n>=12

#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

  //first 12 Grundy numbers after observing the pattern
	vector<int> g = {0,1,2,2,3,3,0,0,0,0,0,0};

	int t;
	cin>>t;s
	while(t--) {
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++) {
			cin>>a[i];
		}

		int res = 0;
		for(int i=0; i<n; i++) {
      //For next grundy numbers after 12,
      //G(n) = G(n/12)  if n>=12
			while(a[i] >= 12) {
				a[i] /= 12;
			}
			res ^= g[a[i]];
		}

		if(res == 0) cout<<"Michael\n";
		else cout<<"Jack\n";
	}
	

	return 0;
}

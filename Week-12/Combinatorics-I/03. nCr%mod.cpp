#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 1e9+7;
const int N = 1e5;

ll fact[N+1];
ll invFact[N+1];

ll power(ll a , ll n){
	ll res = 1;
	
	while(n){
		if(n & 1) res = (res * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}

ll C(int n , int r){
	if(n < r) return 0;
	
	ll result = (fact[n] * invFact[r]) % mod;
	return (result * invFact[n-r]) % mod; 
}

void init(){
	fact[0] = invFact[0] = 1;
	
	for(int i=1;i<=N;i++){
		fact[i] = (fact[i-1] * i) % mod;
		invFact[i] = power(fact[i] , mod - 2);
	}
}

int main(){
	int n , r , t;
	cin>>t;
	
	//to initialize fact[] and invFact[]
	init();
	
	while(t--){
		cin>>n>>r;
		cout<<"C("<<n<<","<<r<<") % mod = "<<C(n , r)<<endl;
	}
}


//

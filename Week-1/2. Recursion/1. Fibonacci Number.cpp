//Problem : Program to find nth fibonacci number

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fib(int n){

	//base case
	if(n==0) return 0;
	if(n==1) return 1;

	// recursive call
	int nth= fib(n-1) + fib(n-2);
	return nth;
}

int main(){
  
	int n;
	cin>>n;
	
	int ans= fib(n);
	cout<<ans;
	
	return 0;
}

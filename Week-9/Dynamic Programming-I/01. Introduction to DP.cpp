/*
When we use recursion to solve certain problems like fibonacci number, we often rcalculate the results which are already calculated which 
might increase the time complexity of the code.

For example, while calculating fibonacci numbers, we make two recursion calls for each number:
  return fib(n-1) + fib(n-2)

  In this, we might end up calculating same value twice for a given number by there two recursion call.
  The approximate time complexity in this case will be 2^(n-1) =~ 2^n

To reduce this complexity, there is a method of storing the precomputed results in an array or vector, so that it could be used for the later function calls

*/

//code for implementation of fibonacci numbers using recursive DP

#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp){
    if(n==0 || n==1) return n;
    if(dp[n]>=0) return dp[n];
    dp[n]= fib(n-1, dp) + fib(n-2, dp);
    
    return dp[n];
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> dp(n+1, -1);
        
        cout<<fib(n, dp);
    }

    return 0;
}

//code for implementation of fibonacci numbers using iterative DP

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int> dp(n+1, -1);
        dp[0]=0, dp[1]=1;
        
        for(int i=2; i<=n; i++){
            dp[i]= dp[i-1] + dp[i-2];
        }
        
        cout<<dp[n]<<"\n";
    }

    return 0;
}

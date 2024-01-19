/*
The problem statement:

bob is standing at the 0th floor, he has to reach the 1st floor by taking n steps on the staircase.
He can take 1 step at a time or 2 or 3.
In how many ways can he reach the first floor?
*/


//code for Implementation:

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = (int)(1e9+7);

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<ll> dp(n+3);
        dp[n]=1; dp[n+1]=0; dp[n+2]=0;
        
        for(int i=n-1; i>=0; i--)
            dp[i]= (dp[i+1] + dp[i+2] + dp[i+3])% mod;
        
        cout<<dp[0]<<"\n";
    }
    return 0;
}

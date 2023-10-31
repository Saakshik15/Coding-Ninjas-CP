/* 

*/

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
  
  //taking inputs
  int n,m,k;
  cin>>n>>m>>k;

  string s;
  vector<char> ch(n);
  loop(i,n) cin>>ch[i];

  //building a flag vector to fast check, which possible character do we have to replace
  vector<int> flag(26);
  loop(i,n) flag[ch[i]-'a']=1;

  //initializing the frequency matrix and setting it to 0
  int freq[k][26];

  loop(i,k){
    loop(j,26){
      freq[i][j]=0;
    }
  }

  //updating the frequency in the frequency matrix
  loop(i,n){
    freq[i%k][s[i]-'a']++;
  }

  //calculate the minimum number of changes for each position in the window of size k & adding it
  int total=0;
  loop(i,k){
    int maxi=0, sum=0;
    loop(j,26){
      sum+= freq[i][j];
      if (freq[i][j]>maxi && flag[j]==1) maxi=freq[i][j];
    }
    total+= (sum-maxi);
  }
  cout<<total<<"/n";
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

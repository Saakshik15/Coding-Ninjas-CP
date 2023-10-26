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

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    
    vector<int>f(26);
    
    int i=0,j=0;
    int total=0;
    int maxlen=0;
    while(j<n){
        if(f[s[j]-'a']==0){
            f[s[j]-'a']++;
            total++;
        }
        else f[s[j]-'a']++;
        if(total<=2) maxlen=max(maxlen,j-i+1);
        else{
            while(i<n && total>2){
                f[s[i]-'a']--;
                if(f[s[i]-'a']==0) total--;
                i++;
            }
        }
      j++;
    }
    cout<<maxlen<<"\n";
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


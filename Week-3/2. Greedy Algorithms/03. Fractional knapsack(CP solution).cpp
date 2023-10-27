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

bool cmp(pair<int,int>&a , pair<int,int>& b){
    double f = (double)a.second/a.first;
    double s = (double)b.second/b.first;
    
    return f>s;
}

void solve(){
    int n,capacity;
    cin>>n>>capacity;
    vector<pair<int,int>>a(n);
    loop(i,n){
        // .first is weight and .second is price
        cin>>a[i].first>>a[i].second;
    }
    
    sort(all(a),cmp);
    
    
    int total_weight=0;
    double profit=0;
    for(int i=0;i<n;i++){
        if(total_weight+a[i].first<capacity){
            total_weight+=a[i].first;
            profit+=(double)a[i].second;
        }
        else{
            int remain = capacity - total_weight;
            profit +=(double)(a[i].second)*((double)remain/a[i].first);
            break;
        }
    }
    cout<<"total profit: ";
    cout<<profit;
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

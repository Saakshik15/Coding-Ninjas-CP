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

int partition(vector<int>& a, int left, int right){
  int pivot = left;
  int end= a[right];

  fr(i, left, right) {
    if(a[i] <= end) {
      swap(a[i], a[pivot]);
      pivot++;
    }
  }
  swap(a[pivot], a[right]);
  return pivot;
}

void quickSort(vector<int>& a, int left, int right){
  //base condition
  if(left>=right) return;

  //finding the pivot element
  int pivot= partition(a, left, right);

  //recursively calling quickSort on the 2 halves, not including the pivot element
  quickSort(a, left, pivot-1);
  quickSort(a, pivot+1, right);
}

void solve() {
  //take the inputs
  int n;
  cin>>n;

  vector<int> a(n);
  loop(i,n) cin>>a[i];

  //call the quickSort function
  quickSort(a, 0, n-1);

  //print the final sorted array
  for(auto i:a) cout<<i<<" ";
  cout<<"\n";
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

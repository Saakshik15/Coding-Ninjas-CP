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

int partition(vector<int>& a, int left, int right){
  int pivot = left;
  int end= a[right];

  fr(i,left,right) {
    if(a[i]<=end){
      swap(a[i], a[pivot]);
      pivot++;
    }
  }
  swap(a[right], a[pivot]);
  return pivot;
}

int quickSelect(vector<int>& a, int left, int right, int k){
  //base condition
  if(left>=right) return a[left];

  //calculating the pivot element's correct position
  int pivot = partition(a, left, right);

  //checking if pivot element is the correct element at that position
  if(pivot+1 == k) return a[pivot];
  //otherwise look for left or right, depending on k
  else if(pivot+1 > k) return quickSelect(a, left, pivot-1, k);
  else return quickSelect(a, pivot+1, right, k);
}

void solve() {
  //taking the inputs
  int n, k;
  cin>>n>>k;

  vector<int> a(n);
  loop(i,n) cin>>a[i];

  //calling quickSort to print the kth smallest and largest number
  cout << quickSelect(a, 0, n-1, k) << " " << quickSelect(a, 0, n-1, n-k+1) << "\n";
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  int t=1;
  //cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }

  return 0;
}

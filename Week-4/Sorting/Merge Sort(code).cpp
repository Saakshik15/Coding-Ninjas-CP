#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fr(i,a,b) for(int i=a; i<=b; i++)
#define loop(x,n) for(int x=0; x<n; ++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

using namespace std;

void precal(){

}

//FUNCTION FOR MERGING THE TWO ARRAYS
void merge(vector<int>& a, int start, int mid, int end){
  vector<int> left, right;
  
  // for(int i=start; i<=mid; i++) left.push_back(a[i]);
  fr(i, start, mid) left.push_back(a[i]);
  fr(i, mid+1, end) right.push_back(a[i]);

  int n=left.size(), m= right.size();
  int l=0, r=0, curr=start;

  //merging the arrays according to the minimum element on both sides
  while (l<n && r<m) {
    if (left[l] < right[r]) {
      a[curr] = left[l];
      curr++; l++;
    } else {
      a[curr] = right[r];
      curr++; r++;
    }
  }

  //remaining elements from the left array
  while(l<n){
    a[curr] = left[l];
    curr++; l++;
  }

  //remaining elements from the right array
  while(r<m){
    a[curr] = right[r];
    curr++; r++;
  }
}

//FUNCTION FOR MERGE SORT
void mergeSort(vector<int>& a, int start, int end){
  
  //base condition
  if(start>=end) return;
  
  //finding the middle element
  int mid = (start+end)/2;
  
  //recursively calling mergeSort on both the halves
  mergeSort(a, start, mid);
  mergeSort(a, mid+1, end);
  
  //merging two sorted halves
  merge(a, start, mid, end);
}

//CALLING FUNCTION FOR MERGE SORT
void solve() {
  
  //taking input
  int n;
  cin >>n;
  vector<int> arr(n);
  loop(i,n) cin>>arr[i];
  
  //calling mergeSort
  mergeSort(arr,0,n-1);
  
  //printing sorted array
  cout<<"\n";
  for(auto i: arr) cout<<i<<" ";
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

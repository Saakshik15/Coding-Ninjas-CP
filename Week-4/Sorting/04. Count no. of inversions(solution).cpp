//Solution code:

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

ll merge(vector<int>& a, int start, int mid, int end){

  //initializing two vectors left and right for storing the left and right lists
  vector<int> left, right;
  fr(i, start, mid) left.push_back(a[i]);
  fr(i, mid+1, end) right.push_back(a[i]);

  //initializing the 2 pointers to iterate over the left and right lists
  ll total =0;
  int n=left.size(), m=right.size();

  int l=0, r=0, curr=start;

  //merge the two lists 
  while (l<n && r<m) {
    if (left[l] <= right[r]) {
      a[curr] = left[l];
      curr++; l++;
    } else {
      a[curr] = right[r];
      total+= n-l;
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

  return total;
}


ll countInversion(vector<int>& a, int start, int end){
  //base condition
  if(start>=end) return 0;
  
  //recursive calls & adding total from all of these recursive calls
  int mid= (start+end)/2;
  ll total=0;

  total+= countInversion(a, start, mid);
  total+= countInversion(a, mid+1, end);
  total+= merge(a, start, mid, end);

  return total;
}

void solve() {
  //taking input 
  int n;
  cin>>n;
  vector<int> a(n);
  loop(i,n) cin>>a[i];

  //calling countInversion function
  cout<< countInversion(a, 0, n-1);
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

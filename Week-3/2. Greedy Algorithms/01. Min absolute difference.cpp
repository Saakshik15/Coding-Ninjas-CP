// Greedy Algorithms are algorithms that choose local optimal choices assuming that they will lead to global optimal solutions.

/*
Problem statement:
given an array, choose two elements such that the absolute difference between them is as minimum as possible.

Approach:

Given the array, the most optimal way of getting minimum absolute differece between two elements is to sort them out.
This way, the elements with the most minimal difference between them will be adjacent to each other.
Then, we will find out all the absolute differences of the adjacent pairs and minimize the diffrerece between them.
*/

//code:

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
    int n;
    cin>>n;

    vector<int> arr(n);
    loop(i,n) cin>>arr[i];

    sort(all(arr));

    int absDiff = INT_MAX;
    loop(i,n-1){
        int diff = abs(arr[i]-arr[i+1]);
        absDiff = min(diff, absDiff);
    }
    cout<<absDiff<<endl;
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  int t=1;
  cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }

  return 0;
}





/*
Problem link: https://codeforces.com/problemset/problem/1462/F

Problem: 

Polycarp found n segments on the street. A segment with the index i is described by two integers li and ri — coordinates
of the beginning and end of the segment, respectively. Polycarp realized that he didn't need all the segments, so he 
wanted to delete some of them.

Polycarp believes that a set of k segments is good if there is a segment [li,ri] (1≤i≤k) from the set, such that it intersects every 
segment from the set (the intersection must be a point or segment). For example, a set of 3 segments [[1,4],[2,3],[3,6]] 
is good, since the segment [2,3] intersects each segment from the set. Set of 4 segments [[1,2],[2,3],[3,5],[4,5]] is not good.

Polycarp wonders, what is the minimum number of segments he has to delete so that the remaining segments form a good set?

Input
The first line contains a single integer t (1≤t≤2⋅105) — number of test cases. Then t test cases follow.
The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of segments. 
This is followed by n lines describing the segments.
Each segment is described by two integers l and r (1≤l≤r≤109) — coordinates of the beginning and end of the segment, respectively.
It is guaranteed that the sum of n for all test cases does not exceed 2⋅10^5.

Output
For each test case, output a single integer — the minimum number of segments that need to be deleted in order for the set of 
remaining segments to become good.
*/


//Approach:

/*
When we draw a segment for the given segments and mark l and r for each segment, we see an observation:

All the segments that have the right value smaller than the left value of the current segment aren't intersecting from left.
All the segments that have the left value larger than the right value of the current segment aren't intersecting from right.

Thus, if we, somehow, know the value of all the segments that are having the right value less than the current segment, 
we can easily extract them out.
So, if we want all the right values smaller than that, we can use binary search over all the segments and find out all right segments,
like all the right values that are smaller than this left value.
For that, we have to sort out this whole segment by the right value.

Similarly, for the other part, when I have to find out the segments that are not intersecting from the right side,
we have to sort them by the left value. 
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
    //take input of the no. of segments and left, right pointers
    int n;
    cin>>n;
    
    vector<pair<int,int>> seg(n);
    vector<int> l(n), r(n);
    
    loop(i,n){ 
        cin>>seg[i].first>> seg[i].second;
        l[i] = seg[i].first;
        r[i] = seg[i].second;
    }
    
    //sort the vector of left and right pointers
    sort(all(l));
    sort(all(r));
    
    //nitialize the miximum answers
    int ans= n-1;
    
    //binary search for each segment and minimize the ans
    loop(i,n){
        int right = lower_bound(all(l), seg[i].second+1)-l.begin();
        int left = lower_bound(all(r), seg[i].first)-r.begin();
        ans= min(ans, n-right+left);
    }
    cout<<ans<<"\n";
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

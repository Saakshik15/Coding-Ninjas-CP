/*
The diameter of a tree is the maximum distance between any two nodes.

To find the diameter of a tree,
for every node:
calculate max left leaf node in the subtree of this node: max_ht[u]
find the max and second max value of max_ht[v] for v being the child node of u.

*/

//Implementation:

#include<bits/stdc++.h>
using namespace std;

const int N= 1e4+5;
vector<int> tree[N];
int height[N];
int max_ht[N];

int main(){
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;

    for(int i=0; i<=n; i++){
      tree[i].clear();
      height[i]= max_ht[i]=0;
    }

    for(int i=0; i<n-1; i++){
      int u,v;
      cin>>u>>v;

      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    
  }
}

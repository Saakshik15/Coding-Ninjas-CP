//code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    priority_queue<int>pq;
    for(int i=0;i<n;i++) pq.push(a[i]);
    
    for(int i=0;i<k;i++){
        if(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }
}

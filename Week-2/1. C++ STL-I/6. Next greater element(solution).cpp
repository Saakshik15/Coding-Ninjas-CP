#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  
   int n;
   cin>>n;
   vector<int>a(n);
   vector<int>b(n); 
   for(int i=0;i<n;i++) cin>>a[i];
   
   stack<int>s;
   for(int i=n-1;i>=0;i--){
       if(s.empty()){
           b[i]=-1;
           s.push(a[i]);
       }
       else{
           while(!s.empty() && s.top()<=a[i]) s.pop();
           if(s.empty()){
               b[i]=-1;
               s.push(a[i]);
           }
           else{
               b[i]=s.top();
               s.push(a[i]);
           }
       }
   }
   
    // printing the new vector with the next greater element
   for(int i=0;i<n;i++) cout<<b[i]<<" ";

  return 0;
}

//code:

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,target;
  cin>>n>>target;
  vector<int>a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  
  if(a.size()==0){
      cout<<-1<<" "<<-1;
      return 0;
  }
  int left = lower_bound(a.begin(),a.end(),target) - a.begin();
  int right = upper_bound(a.begin(),a.end(),target) - a.begin();
  
  if(left>=n){
      cout<<-1<<" "<<-1;
      return 0;
  }
  if(a[left]==target) cout<<left<<" "<<right-1;
  else{
      cout<< -1 <<" " << -1;
      return 0;
  }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

void solve(){
  //taking input
  int n;
  cin>>n;
  
  vector<int>arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];

  //find the maximum and minimum element in the array
  int maxi = *max_element(arr.begin(), arr.end());
  int mini = *min_element(arr.begin(), arr.end());
  
  //initialize a vector with the number of elements equal to diff bwn max and mn num
  vector<int>freq(maxi-mini+1);

  //update the frequency of each number shifted by the minimum number
  //this will make min no always shift to 0
  for(int i=0; i<n; i++) freq[arr[i]-mini]++;

  //print the sorted array shifting the numbers to original forms
  for(int i=0; i<freq.size(); i++){
    for(int j=0; j<freq[i]; j++) cout<<(i+mini)<<" ";
  }
}

int main(){
  int t;
  cin>>t;

  while(t--){
    solve();
  }
}

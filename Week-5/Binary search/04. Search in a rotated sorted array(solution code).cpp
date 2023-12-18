#include <iostream>
#include <bits/stdc++.h>
#define ll long long
usng namespace std;

int biarySearch(vector<int>& nums, int left, int right, int target){
  while(left<=right){
    int mid = left+(right-left)/2;

    if(nums[mid] == target) return mid;
    else if(nums[mid] < target) left=mid+1;
    else right = mid-1;
  }
  return -1;
}

int findLargetElement(vector<int>& nums, int left, int right){
  int n= nums.size();

  while(left<=right){
    int mid = left+(right-left)/2;

    if(mid-1>=0 && mid+1<n && nums[mid-1] <nums[mid] && nums[mid+1] < nums[mid]) return mid;
    else if(mid==0 && mid+1 <n && nums[mid+1] < nums[mid]) return mid;
    else if(mid==n-1 && mid-1 >= 0 && nums[mid-1]<nums[mid]) return mid;

    if(nums[mid>=nums[left]) left= mid+1;
    else right= mid-1;
  }
  return -1;
}

void solve(){
  int n;
  cin>>n;

  vector<int> nums(n);
  for(int i=0; i<n; i++) cin>>nums[i];

  int pivot= findLargestElement(nums,0,n-1);

  int q;
  cin>>q;
  while(q--){
    int x; cin>>x;

    int res1 = binarySearch(nums,0,pivot,x);
    int res2 = binarySearch(nums, pivot+1, n-1, x);

    if(res1 != -1) cout<<res1<<"\n";
    else if(res2 != -1) cout<<res2<<"\n";
    else cout<<-1<<"\n";
  }
}

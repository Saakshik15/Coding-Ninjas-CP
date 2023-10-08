/*
Problem:

You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements
such that they add up to Target.
Note:
We cannot use the element at a given index twice.
*/

//code:

#include<bits/stdc++.h>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n){

    unordered_map<int, int> mp;
    vector< pair<int, int> > ans;

    for(int i = 0 ; i < n ; i++){
        int temp = target - arr[i];
        if(mp[temp] > 0){
            ans.push_back({arr[i], temp});
            mp[temp]--;
        }
        else{
            mp[arr[i]]++;
        }
    }
    if(ans.size() == 0) ans.push_back({-1,-1});
    return ans;
}

/*
You are given with an integer k and an array of integers that contain numbers in random order. 
You have to find k largest numbers from given array. You need to save them in an array and return it.
*/

//code:

#include<bits/stdc++.h>

vector<int> kLargest(int arr[], int n, int k) {
    
    priority_queue<int> pq;
    vector<int> ans;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }

    for(int i=0; i<k; i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

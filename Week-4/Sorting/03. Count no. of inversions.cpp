/*
Problem Statement: 
Given an array of N integers, count the inversion of the array (using merge-sort).
Inversion: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
*/

//solution:

#include <bits/stdc++.h> 
#define ll long long

ll merge(ll arr[], int low, int mid, int high){
    vector<int> temp;
    int cnt=0;

    int l=low, r=mid+1;

    while(l<=mid && r<=high){
        if(arr[l]<arr[r]){
            temp.push_back(arr[l]);
            l++;
        }else{
            temp.push_back(arr[r]);
            cnt+= mid-l+1;
            r++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        temp.push_back(arr[r]);
        r++;
    }

    //making changes to the arr according to the sorted array temp
    for(int i=low; i<=high; i++) arr[i] = temp[i-low];

    return cnt;
}

ll mergeSort(ll arr[], int low, int high){
    int cnt=0;

    if(low>=high) return cnt;

    int mid=(low+high)/2;

    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);
    cnt+=merge(arr,low,mid,high);

    return cnt;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}


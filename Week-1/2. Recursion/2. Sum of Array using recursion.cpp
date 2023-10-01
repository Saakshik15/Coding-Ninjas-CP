//Problem :  Finding sum of array using recursion

//code : traversing the array from the end

#include<iostream>
#include "Solution.h"
using namespace std;

int sum(int input[], int n) {

    //base case
  if(n==0) return 0;
    //recursive call
  return input[n-1] + sum(input, n-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) cin >> input[i];
    
    cout << sum(input, n) << endl;
}



//code: traversing from the beginning

#include <bits/stdc++.h>
// #include<iostream>
using namespace std;

//recursive function
int sumOfArr(int curr, int n, vector<int> arr){
    //base case
    if(curr == n) return 0;

    //recursive call
    return arr[curr] + sumOfArr(curr+1, n, arr);
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans = sumOfArr(0, n, arr);
    cout<<ans;

    return 0;
}

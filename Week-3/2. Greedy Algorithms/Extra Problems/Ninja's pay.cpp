/*
Ninja works in an XYZ MNC which follows a very strict rule regarding the pay. Ninja has been assigned ‘N’ tasks. 
Each task requires some days to finish, which is given in the form of an array ‘TIME’. For each day of delay before 
starting to work in task ‘i’ a loss is incurred on Ninjas’ pay which is given in an array ‘LOSS’. Ninja asks you for 
help to find the order in which the tasks should be completed such that there is a minimum loss in Ninjas’ pay.
If there are multiple solutions, print the order with the smallest indices first.
*/

//code:

#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    double t1 = (double)a[0]/ a[1];
    double t2 = (double)b[0]/ b[1];
    if(t1 != t2) return t1 < t2;
    return a[2] < b[2];
}
vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    vector<vector<int>> v;
    for(int i = 0 ; i < n ;i++){
      v.push_back({time[i], loss[i], i});
    }

    sort(v.begin(),v.end(),comp);

    vector<int> ans;
    for (auto x : v) {
      ans.push_back(x[2] + 1);
    }
    return ans;
}

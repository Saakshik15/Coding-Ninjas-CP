/* You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250 */


#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fr(i,a,b) for(int i=a; i<b; i++)
#define loop(x,n) for(int x=0; x<n; ++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

using namespace std;

struct job{
    int startTime;
    int endTime;
    int jobProfit;
};

void precal(){

}

bool compare(job a, job b){
    return a.endTime < b.endTime;
}

// Function to find the latest non conflicting job.
int nonConflictingJob(vector<job> &jobs, int i){
    int low = 0;
    int high = i - 1;
    int ans = -1;

    while (low <= high){
        int mid = (low + high) / 2;

        if (jobs[mid].endTime <= jobs[i].startTime){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit){

    int n = start.size();

    // Creating jobs array of size N.
    vector<job> jobs(n);

    for (int i = 0; i < n; i++){
        jobs[i].startTime = start[i];
        jobs[i].endTime = end[i];
        jobs[i].jobProfit = profit[i];
    }

    // Sorting the jobs in the increasing order of end time.
    sort(jobs.begin(), jobs.end(), compare);

    // Creating a dp array of size N.
    vector<long long int> dp(n);

    dp[0] = jobs[0].jobProfit;

    for (int i = 1; i < n; i++){
        // First calculating the profit by excluding the current job.
        long long int excProfit = dp[i - 1];

        // Then, calculating the profit by including the current job.
        long long int incProfit = jobs[i].jobProfit;

        // Finding the index of closest non conflicting job to current job.
        int index = nonConflictingJob(jobs, i);

        // If the index is not equal to -1, adding the profit of that job.
        if (index != -1) incProfit += dp[index];
    
        // Updating the dp array.
        dp[i] = max(incProfit, excProfit);
    }
    return dp[n - 1];
}

void solve() {
  int n;
  cin>>n;

  vector<int> start(n), end(n), profit(n);

  loop(i,n) cin >> start[i] >> end[i] >> profit[i];

  cout<<findMaxProfit(start, end, profit);
}

int main(){

  fast_io;
  cout<<fixed;
  cout<< setprecision(10);
  precal();
  int t=1;
  //cin >>t;
  for(int i=1; i<=t; i++){
    //cout<< "Case #" << i << ": ";
    solve();
  }

  return 0;
}

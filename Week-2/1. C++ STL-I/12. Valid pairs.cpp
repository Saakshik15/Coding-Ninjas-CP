/*
Problem:

Given an array of integers and numbers k and m, write a function that returns true if given array can be divided 
into pairs such that the sum of every pair gives remainder m when divided by k.

Sample Input :
4
2 1 5 7
9
3
Sample Output :
true

Explanation :
Pairs will be (2,1) and (5,7)
*/

//code:

bool CheckSumPairs(int arr[], int n, int k, int m) {
	if(n%2!=0) return false;
    
    unordered_map<int,int> count;
  
    for(int i=0;i<n;i++){
        count[arr[i]%k]++;
    }
  
    int first,second;
    for(int i=0;i<n;i++){
        first = count[arr[i]%k];
        second = count[(m-arr[i]%k+k)%k];
        if(first!=second){
            return false;
        }
    }
    return true; 
}

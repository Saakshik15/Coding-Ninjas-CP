/*
Problem:
You are given an array of ‘N’ integers. You have to find the maximum sum over all subarrays of size ‘K’.
*/

//code:

int maxOfK(int n, int k, vector<int> &num){
    
    int i=0, j=0;
    int maxSum = 0, curSum=0;

    while(j<n){

        sum+= arr[j];

        if(j-i+1 == k){
            maxSum = max(curSum, maxSum);
            curSum -= arr[i];
            i++;
        }
        j++;
    }
    return maxSum;
}

/*
Prateek is a kindergarten teacher. He wants to give some candies to the children in his class.  
All the children stand in a line and each of them has a grade according to his or her performance in the class.  
Prateek wants to give at least one candy to each child. If two children are standing adjacent to each other, 
then the one with the higher rating must get more candies than the other. Prateek wants to minimize the total 
number of candies he must buy.

Given an array 'STUDENTS' of size 'N' that contains the grades for each student, your task is to find what is the 
minimum number of candies Prateek must buy so that he can distribute them among his students according to the criteria given above.
*/

//code:

int requiredCandies(vector < int > &arr) {
    int n = arr.size();
    vector<int>vis(n,1);
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            vis[i]=1+vis[i+1];
        }
    }

    int sum=vis[0];
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1] && vis[i]<=vis[i-1]){
            vis[i]=1+vis[i-1];
        }
        sum+=vis[i];
    }
    return sum;
}

/*
Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to group all the array 
elements with ‘K-th’ bit (rightmost bit is ‘1st’ bit) equal to 0 followed by all the elements with ‘K-th’ bit equal to 1.

Note 1: The relative order inside both the groups should remain as it was in the input.

Note 2: You have to return the modified array/list..

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 1, then after modification, ‘ARR’ should be {2,4,1,3} because ‘K-th’ (‘K’ = 1) 
of {2,4} is 0 and ‘K-th’ bit of {1,3} is 1.
*/

/*
Constraints:
1 <= T <= 10
1 <= N <= 10^4
1 <= ARR[i] <= 10^9
1 <= K <= 31

Time Limit: 1 sec

Sample Input 1:
2
4 1
4 3 2 1
5 2
2 5 1 6 7

Sample Output 1:
4 2 3 1
5 1 2 6 7

Explanation For Sample Input 1:
In example 1, the original ‘ARR’ is {4,3,2,1} and ‘K’ = 1. After modification, the ‘ARR’ should be {4,2,3,1} 
because {4,2} will come first as their 1st bit is 0 and {3,1} will come after that as their 1st bit is 1.

Sample Input 2:
2
5 1
3 6 2 1 4
5 3
7 6 2 9 3

Sample Output 2:
6 2 4 3 1
2 9 3 7 6

Explanation For Sample Input 2:
In example 2, the original ‘ARR’ is {7,6,2,9,3} and ‘K’ = 3. After modification the ‘ARR’ should be {2,9,3,7,6} 
because {2,9,3} will come first as their 3rd bit is 0 and {7,6} will come after that as their 3rd bit is 1.
*/


//code:

vector < int > sortArrayByKBit(int n, int k, vector < int > & arr) {
    int j = 0, p = 0;

    vector < int > temparr(n);
    for (int i = 0; i < n; i++) {
        if ((arr[i] >> (k - 1)) % 2 == 0) arr[p++] = arr[i];
        else temparr[j++] = arr[i];
    }

    j = 0;
    for (int i = p; i < n; i++) arr[i] = temparr[j++];
    
    return arr;
}

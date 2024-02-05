/*
Problem statement
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list 
in a 'single scan'.

'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element 
in the array/list just once.

Note:
1. You need to change in the given array/list itself. Hence, no need to return or print anything. 
2. You are not allowed to sort the list/array directly.
*/


//code:

//solved using dutch national flag algo

void sort012(int *nums, int n)
{
    int low=0;
    int mid=0;
    int high= n-1;

    while(mid <= high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++; mid++;
        }
        else if(nums[mid] ==1 ) mid++;
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

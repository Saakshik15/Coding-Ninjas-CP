/*
given a sorted array of integers and an integer k, return the index of first and last occurrence of that integer in the array.
eg, for array: [1, 2, 2, 2, 3, 3, 4, 5, 5] and integer k=2
then the first occurrence of the integer 2 is at index 1 and last occurrence is at index 3
if there is only one occurrence then return the same index and if no such index exists, the function should return -1, -1
*/

/*
Since the array is sorted and we have to find the index of occurrence of the element in the array,
we can use the lower_bound() and upper_bound() functions to find the occurrence of the element in the array.

the lower_bound() function will return the pointer to the first occurrence of the number if found and if not found it will return the next greater element.
and the upper_bound() function will return pointer to the next index at which the element is present.
so, the lower_bound() will return the correct index but in case of upper_bound() we will subtract 1 from the index obtained in order to find index to given element.
*/

#include<bits/stdc++.h>

vector<int> searchRange(vector<int> &arr, int x){
	vector<int> result;
    
    auto lower = lower_bound(arr.begin(), arr.end(), x);
    auto upper = upper_bound(arr.begin(), arr.end(), x);
    
    if (lower != arr.end() && *lower == x) {
        result.push_back(lower-arr.begin());
        result.push_back(upper-arr.begin()-1);
    } else {
        result.push_back(-1); 
        result.push_back(-1);
    }
    return result;
}


//time complexity : O(2*logN) for both upper_bound() and lower_bound()
//space complexity: O(N) in order to store the array elements

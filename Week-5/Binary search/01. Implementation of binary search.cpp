// pseudo-code for binary search

BinarySearch(nums, target){
  lb=0, ub=nums.length-1;

  while(lb<=ub){
    mid = lb+ (ub-lb)/2;

    if(nums[mid] == target) return true;
    else if(nums[mid] < target) lb= mid+1;
    else if(nums[mid] > target) ub= mid-1;
  }
  return false;
}


// built-in library functions for binary search:
Binary_Search();
lower_bound();
upper_bound();


Binary_search(): 
  returns boolean true if target is present in the array/vector.
  else if target is not present then returns false.

lower_bound():
  returns pointer to target if has only one occurance
  returns pointer to the first target if has multiple occurances
  returns pointer to the next higher target if has no occurance

upper_bound():
  returns pointer to the next higher target in all above conditions


// types of problems binary search is generally used for

1. Searching in a sorted array
2. Step-up function / step-down function / peak value function
3. Maximize the minimum value




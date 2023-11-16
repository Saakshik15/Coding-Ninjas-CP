/*
Merge sort:

Merge sort is a sorting algorithm which works on the principle of divide and conquer.

Divide and conquer is a simple way that divides the problem into smaller halves and try to conquer or solve for smaller halves and combine them.
*/
//The general algorithm goes like:

mergeSort(arr, l, r){

  //finding the mid to divide th array into two halves
  int mid= (l+r)/2;

  //dividing the array into two halves
  mergeSort(arr, l, mid);
  mergeSort(arr, mid, r);

  //combining the array while solving for smaller parts
  merge(a,b);
}

/*
Time complexity for Merge sort will be: O(N logN) 
since Merging takes O(N) time and dividing takes O(logN) time.

and space complexity will be O(logN) for the stack used for recursion calls 
and since we are doing in place sorting, no extra space for arrays is used.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

  //initializing a vector
  vector<int> arr = {3, 5, 1, 2, 4};

  //to apply binary search algorithms and functions related to binary search, we have to sort the vector first
  sort(arr.begin(), arr.end());

  if(binary_search(arr.begin(), arr.end(), 2)
    cout << "Present in the array." << endl;
  else
    cout << "Not present in the array." << endl;


  //initializing a vector
  vector<int> arr1 = {2, 2, 2, 3, 3, 3, 6, 6, 7};
  //sorted vector with same number occurring multiple times

  //lower_bound() on a vector
  //lower_bound(a.begin(), a.end(), num);
  
  //lower bound function on sorted array returns the pointer to:
  //position: if only one occurrence of the element is found in the vector
  //first position: if multiple occurances of the same element are found in the vector
  //position of number just greater than the number: if no occurance of the number is found in the vector

  int lowerBoundPointer = lower_bound(arr1.begin(), arr1.end(), 3);
  int lowerBoundIndex = lower_bound(arr1.begin(), arr1.end(), 3) - arr1.begin();
  cout << "Pointer to Lower bound is: " << lowerBoundPointer << " and the index of lower bound is : " << lowerBoundIndex << endl;


  //upper_bound() on a vector
  //upper_bound(a.begin(), a.end(), num);

  //upper bound on a sorted vector returns the pointer to:
  //position of next higher number: in case of one occurance
  //first position of the next higher number: in case of multiple occurrences
  //position of number just greater than the number: in case of no occurrence

  //upper bound will not point to the last occurrence of the number, but at the next element to where the given nummber is occurred last time.

  int upperBoundPointer = upper_bound(arr1.begin(), arr1.end(), 3);
  int upperBoundIndex = upper_bound(arr1.begin(), arr1.end(), 3) - arr1.begin();
  cout << "Pointer to Upper bound is: " << upperBoundPointer << " and the index of upper bound is : " << upperBoundIndex << endl;

  //remember that these functions use binary search internally so the array or vector must be sorted.

  //lower bound and upper bound can be applied to any container which has sorted data.
  //eg. set has sorted data so, we can also use lower bound and upper bound on sets.
}

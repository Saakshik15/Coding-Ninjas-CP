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
  //sorted vector with same number occuring multiple times

  //lower_bound() on a vector
  //lower bound function on sorted array returns the pointer to:
  //position: if only one occurance of the element is found in the vector
  //first position: if multiple occurances of the same element are found in the vector
  //position of number just greater than the number: if no occurance of the number is found in the vector

  int lowerBound = lower_bound(arr1.begin(), arr1.end(), 3);
}

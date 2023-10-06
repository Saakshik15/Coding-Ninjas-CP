#include <bits/stdc++.h>
using namespace std;

int main(){

  //STL arrays
  
  //initializing arrays:
  
  array<int, 5> arr1;    
  //initialized an array of size 5 of int datatype having size 5

  array<int, 5> arr2 = {1,2,3,4,5};    
  //initialized an array of size 5 of int type with elements 1,2,3,4,5

  array<int, 10> arr3 = {1,2,3,4,5};
  //initialized an array of size 10 with first 5 elements as 1,2,3,4,5 and rest of them will be initialized with 0.

  //when STL arrays are initialized with a defined size, all the elements are initialized with 0.

  
  //to find out the number of elements of a array, we can use:
  int len = arr1.size();

  //to fill all the elements of the array with a number:
  arr1.fill(1);

  //we can access the elements of the array with their indexes.
  //indexing in the array starts from 0

  //we can find out if the array is empty by:
  bool isEmpty = arr1.empty();

  //first element of the array
  int first = arr1.front();

  //last element of the array
  int last = arr1.back();
  
}

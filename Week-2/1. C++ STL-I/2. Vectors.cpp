#include <bits/stdc++.h>
using namespace std;

int main(){

  //STL vectors are dynamic sized cntainers and we can change their size during runtime.

  //initialization of vectors
  vector<int> arr;

  //we can initialize vectors as: vector<datatype> vectorname;

  //if we want to initialize some elements of the vector,
  vector<int> arr2 = {1,2,3,4,5};

  //if we want to give some size to the vector at the time of initialization, we can give as:
  vector<int> arr3(10);

  //if we want to create a vector with a specified size and initialize all the elements with one element,
  vector<int> arr4(10,1);


  //nested vectors/ matrices
  //in order to create 2d vectors or matrices, we can create neste vectors like:
  vector<vector<int>;
  //this will create a 2d vector of data type int

  vector<vector<int>> arr5(10, vector<int>(10,5);

  //creating a 2d vector of strings all initialized with "CN"
  vector<vector<string>> arr6(3, vector<string>(4,"CN");


  //size of vector
  int size = arr4.size();

  //to access elements of the vector, we can use indexes for the elements. Indexing starts from 0 in vectors as well.

  //as vector is a dynamic container, we can insert elements during the runtime at the back of the vector
  //to insert the elements at the end of the vector, 
  arr2.push_back(2);
  //will push back the element at the end of the vector

  //we can also remove the last element from the back of the vector by
  arr2.pop_back();

  //both the push_back() and pop_back() take O(1) time.
  //but we can also push at any other index of the vector in O(N) time+

  //first element of the vector:
  int first = arr2.front();

  //first element of the vector:
  int last = arr2.back();

  //clear all the elements from the vector:
  arr2.clear();

  //check if the vector is empty or not:
  arr2.empty();
  
  
}

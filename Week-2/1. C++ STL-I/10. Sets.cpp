//set is a container in which every element is unique.
//the values in the set are stored in specific sorted order, ie. either ascending or descending in set.

#include<bits/stdc++.h>
using namespace std;

int main(){

  //**********set and unordered set**********
  //both set and unordered set only contain distinct elements
  
  //set:
  //increasing order(by default), uses self balancing BST
  //search, insertion and deletion: O(logN)

  //unordered set:
  //no ordering, hash table
  //search, insertion and deletion: O(1), worst: O(N)

  
  //initializing set and unordered set
  set<int> st;
  unordered_set<int> st1;

  //insertion of elements:
  st.insert(8);
  st.insert(1);
  st.insert(2);
  //no duplicate elements allowed in set or unordered set

  //number of elements in the set and unordered set:
  int size = st.size();

  //first and last elements of the set(preferred on set only as it contains elements in sorted order)
  int first = *st.begin();
  int last = *(--st.end());
  //begin() is pointer to the first element and end() is the pointer to the end(after the last element) of the set

  //we can also use begin() and end() on unordered set, but since it contains elements in an unordered manner,
  // it is not preferred to use it on unordered set
  
  //print all the elements in the set and unordered set
  for(auto it: st){
    cout<<it<<endl;
  }
  
  //check if an element is present in the set or not
  int c1= count(element);
  //if c1 = 0 then the element is not in the set and if c1 = 1 then 
  //the element is present in the set since set stores an element only once

  //remove an element from the set
  st.erase(2);
  st.erase(st.begin());
  //you can write pointer too

  //remove all the elements from the set
  st.clear();



  //**********MULTISET**********
  
  //multisets are type of associative containers similar to sets, with the exception that 
  //it can store a single value more than once unlike the sets

  //initializing a multiset
  multiset<int> mst;                  //increasing order
  multiset<int, greater<int>> mst2;   //decreasing order

  //inserting in a multiset
  mst.insert(1);
  mst.insert(2);
  mst.insert(3);
  mst.insert(1);
  //[1,1,2,3]

  //iterate over the elements in a multiset
  for(auto it:mst){
    cout<< it<< endl;
  }
  
  //to find an element in a multiset,
  mst.find(2);
  
  //if we use the erase() function on the multiset, then the function will delete all the instances of that element from the multiset
  //for erasing only one instance of an element, we can use a pointer to the element in the set
  mst.erase(mst.find(2));
  
  //other functions used for the multisets are similar to sets and unordered sets.
  
}

//map is a data sturucute that stores a key-value pair.
//a key is mapped to a value
//a map cannot have a single key mapped to 2 different values but 2 keys can have same value
//by default, the map stores the values in sorted order according to the values of the keys

#include<bits/stdc++.h>
using namespace std;

int main(){

  //initializing a map, unordered_map and multimap
  map<string, int> mp1;
  unordered_map<string, int> mp2;
  multimap<string, int> mp3;

  //insert elements in the map:
  mp1["saakshi"] = 123;
  mp1["sumeet"] = 234;

  mp2["saakshi"] = 123;
  mp2["sumeet"] = 234;

  mp3 = {{"saakshi", 123}, {"sumeet", 234}};

  //accessing value using keys:
  int val1 = mp1["saakshi"];
  int val2 = mp1["sumeet"];

  //finding out the size of the map
  int size = mp1.size();

  //check if a key is present in a map:
  int c1= mp1.count("saakshi");
  //if c1=0 then the string is not present in the map, or if it is any other value then it is present in the map

  //iterate over all the key value pairs in the map:
  for(auto it: mp1){
    cout<< it.first << it.second << endl;
  }

  //erase the key value pair from the map:
  mp1.erase("saakshi");

  //clear the map
  mp1.clear();
}

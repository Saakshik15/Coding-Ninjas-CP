//Pairs: Pairs are also containers provided by the C++ STL libary which are capable of storing two different data types in a single entity.

#include <bits/stdc++.h>
using namespace std;

int main(){

  //initializing pairs:
  //pair<data_type_1, data_type_2> p;
  
  pair <string, int> p;

  //we can assign values to pais as in follwing ways:
  p = {"Saakshi", 58};

  //or we can use the make_pair() function as:
  p = make_pair("Saakshi", 58);

  //pairs are useful to make a vector of pairs 

  //making vector of pairs

  vector<pair<string, int>> phone_book;

  //pushing the values to the vector:

  phone_book.push_back({"Saakshi", 12345});
  phone_book.push_back({"CodingNinja", 98765});
  phone_book.push_back({"Coder", 54321});

  cout<< "Phone Book : \n";

  for(auto i: phone_book){
    cout << i.first << ": " << i.second << "\n";
  }
  
  return 0;
}

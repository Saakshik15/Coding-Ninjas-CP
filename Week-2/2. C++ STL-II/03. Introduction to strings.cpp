#include <bits/stdc++.h>
using namespace std;

int main(){

  string str;
  cout << "Input a string : " ;
  cin >> str;
    
  //length of the string
  // str.length() or str.size()
  
  cout << "String is : " << str << endl;
  cout << "Length of the string is: " << str.length() << endl;

  //pop_back() and push_back(char) functions
  //because of strings are similar to vectors, we can push and pop characters from them from the end
  
  str.push_back('k');
  cout << "New string after appending character 'k' is : " << str <<endl;

  str.pop_back();
  cout << "string after removing the last character from the string is : " << str << endl;

  //getline()
  //this function helps to input strings from the console which have spaces in them as cin doesn't input anything after the space

  //clearing the input buffer before using getline as we have already used cin so there might be any remaining characters in buffer
  cin.ignore();
  
  string str2;
  cout << "Input a string with spaces : " ;
  getline(cin, str2);
  cout << "String with spaces : " << str2;
  
  //substr() function
  //this function is used for extraction of some continuous characters from the string
  //this function takes two parameters: starting index, and length you want to extract out
  //eg. str.substr(0, 4);

  cout << "Extracted string of length 4 from 0th index: " << str.substr(0, 4) << endl;
  //output : saak
}


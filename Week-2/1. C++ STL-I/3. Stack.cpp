#include <bits/stdc++.h>
using namespace std;

int main(){

  //initializing stack
  stack<int> stk;
  //stack<datatype> stackname;

  //insert elements at the top of the stack
  stk.push(2);
  stk.push(3);

  //pop elements from the top of the stack
  stk.pop();

  //get the top element of the stack
  int top = stk.top();

  //number of elements in the stack
  int size = stk.size();

  //check if the stack is empty or not 
  bool isEmpty = stk.empty();

  //print and pop all the elements from the stack
  while(!stk.empty()){
    cout << stk.top() << endl;
    stk.pop();
  }
  
}

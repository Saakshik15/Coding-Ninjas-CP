#include <bits/stdc++.h>
using namespace std;

int main(){

  //elements are inserted from the back of the queue and removed from the front of the queue

  //queue
  
  //initialize a queue
  queue<int> que;
  //queue<datatpe> queue-name;

  //insert elements from the back of the queue
  que.push(2);
  que.push(5);
  que.push(1);

  //pop elements from the front of the queue
  que.pop();

  //front and back of the queue
  int front = que.front();
  int back = que.back();

  //size of the queue
  int len = que.size();

  //check if the queue is empty or not
  bool isEmpty = que.empty();

  //print and remove all the elements from the queue
  while(!que.empty()){
    cout<< que.front() <<endl;
    que.pop();
  }


  //deque

  //can insert or take out the elements from both the ends of the queue

  //initialize a deque
  deque<int> dq;
  //deuque<datatype> deque-name;

  //push elements from the front
  dq.push_front(1);
  dq.push_front(4);

  //push elements from the back
  dq.push_back(2);
  dq.push_back(3);

  //pop elements from the front
  dq.pop_front();

  //pop the elements from the back
  dq.pop_back();

  //get the front element of the deque
  int front = dq.front();

  //get the back element of the deque
  int back = dq.back();
  
  //check if the deque is empty
  bool isEmpty = dq.empty();

  //find the size od the deque
  int len = dq.size();
  
  //print all the elements of the deque using iterators
  for(auto i= dq.begin(); i != dq.end(); i++){
    cout<< *i ;
  }

  //print and pop all the elements from the deque
  while(!dq.empty()){
    cout<< dq.front() << endl;
    dq.pop_front();
  }

}

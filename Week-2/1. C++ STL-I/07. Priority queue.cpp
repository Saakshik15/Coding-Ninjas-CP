//priority queue is a container that queues elements based on some priority.
//the queue follows the FIFO property but priority queue pops the elements based on their priority
//priority queues are built on top of heaps(max heap by default) and uses an array of vector as an internal structure

//max-heap priority queue:
//the top element is the maximum in the priority queue and as we go down the priority queue the value decreases

//min-heap priority queue:
//the top element is the minimum in the priority queue and as we go dowm the priority queue the value increases

#include <bits/stdc++.h>
using namespace std;

int main(){

  //initialize a priority queue:
  
  //max heap priority queue(by default)
  priority_queue<int> pq_max;
  //min-heap priority queue
  priority_queue<int, vector<int>, greater<int>> pq_min;

  //note: one common technique seen in priority queues is that instead of using a min heap, 
  //  switch the sign of the input data in max-heap priority queue

  //min-heap priority queue using comparator function
  //comparator:
  struct cmp{
    public:
      bool operator() (int &a, int &b) {return a>b;}
  };

  //priority queue using comparator:
  priority_queue<int, vector<int>, cmp> pq_min2;

  //pushing elements inside max and min heap priority queue:
  pq_max.push(8);
  pq_max.push(1);
  pq_max.push(5);
  pq_max.push(3);
  //[8, 5, 3, 1]

  pq_min.push(8);
  pq_min.push(1);
  pq_min.push(5);
  pq_min.push(3);
  //[1, 3, 5, 8]

  //number of elements in an priority queue:
  int size = pq_max.size();

  //top element of the priority queue(element with the highest priority)
  int val = pq_min.top();

  //pop the top element in the priority queue:
  pq_max.pop();
  pq_min.pop();

  //check if priority queue is empty or not
  bool empty = pq_max.empty();
  
  // print all the elements in the priority queue
  while(!pq_max.empty()){
    cout<< pq_max.top() <<endl;
    pq_max.pop();
  }
  
}

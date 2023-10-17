#include <bits/stdc++.h>
using namespace std;

int main(){

  //initialize a vector and a string
  vector<int> arr1 = {1, 5, 3, 4};
  string str = "SaakshiKobarne";

  //reverse string and vector
  //vector
  reverse(arr1.begin(), arr1.end());
  for(auto i:arr1){
    cout << i << " ";
  }
  cout << endl;
  //string
  reverse(str.begin(), str.end());
  cout << "reversed string :" << str << endl;

  //maximum value in the vector and the index of the maximum value
  int maxEleIndex = max_element(arr1.begin(), arr1.end()) - arr1.begin();
  int maxEle = *max_element(arr1.begin(), arr1.end());

  cout << "Maximum element is : " << maxEle << " and present at index : " << maxEleIndex << endl;

  //minimum value in the vector and the index of the minimum value
  int minEleIndex = min_element(arr1.begin(), arr1.end()) - arr1.begin();
  int minEle = *min_element(arr1.begin(), arr1.end());

  cout << "Minimum element is : " << minEle << " and present at index : " << minEleIndex << endl;

  //maximum function and minimum function
  int a=1, b=2, c=3;
  //maximum of two numbers
  int maxi = max(a,b);

  //max of three numbers
  int maxVal = max(a, max(b,c));

  //to avoid complex nesting, we can also use curly braces inside the brackets as:
  maxVal = max({a,b,c});

  //similarly, we also have function to find out the minimum as:
  int mini = min(a,b);
  int minVal = min(a, min(b,c));
  minVal = min({a,b,c});

  cout << "The maximum value among all is: " << maxVal << "and the minimum value is: " << minVal << endl;
  
  //sum of all the numbers in the vector: accumulate function
  
  int sum = accumulate(arr1.begin(), arr1.end(), 0);
  //sum = accumulate(pointer to begining index, pointer to end index+1, initial sum);
  cout << "Sum of all the numbers in the vector is: " << sum << endl;

  //sort a given vector: 
   //arr1: {1, 5, 3, 4}
  
  //ascending order:
  sort(arr1.begin(), arr1.end());
  for(auto i: arr1){
    cout << i << " ";
  }
  cout << endl;
  //output: {1, 3, 4, 5}

  //descending order:
  sort(arr1.begin(), arr1.end(), greater<int>());
  for(auto i: arr1){
    cout << i << " ";
  }
  cout << endl;
   //output: {5, 4, 3, 1}

  //we can also sort the vector in descending order using rbegin() and rend()
  sort(arr1.rbegin(), arr1.rend());
  for(auto i:arr1){
    cout << i << " ";
  }
  cout << endl;
  //output: {5, 4, 3, 1}

  //descending order using comparator:
  bool cmp(int &a, int &b){ return a>b };
  sort(arr1.begin(), arr1.end(), cmp);
  for(auto i:arr1){
    cout << i<< " ";
  }
  cout << endl;

  //sort the vector of pairs by descending order of second element in the pair using comparator

  bool cmp(pair<int, int> &a, pair<int,int> &b) { return a.second > b.second; }
  
  vector<pair <int, int>> arr2 = {{1,2}, {7,8}, {4,5}, {2,3}};
  
  sort(arr2.begin(), arr2.end(), cmp);
  for(auto i:arr1){
    cout << i<< " ";
  }
  cout << endl;
  
}

//Iterators:

//iterators are smart pointers which will autonatically detect on what container we are pointing to, so that we can iterate over that container.

//code:

#include <bits/stdc++.h>
using namespace std;

int main(){

  //iterators on vector
  vector<int> a = {1,2,3,4,5};
  
  cout << "Iterate over vector : ";
  for(auto i: a) cout << i << " ";
  cout << endl;

  
  //iterators on map
  map<int,int> mpp;
  mpp[0]= 1;
  mpp[1]= 1;
  mpp[2]= 1;
  mpp[3]= 1;

  cout<< "Iterate over map: " << endl;
  for(auto i:mpp) cout << i.first << ": " << i.second <<"\n";


  //iterators on set
  set<int> st;
  st.insert(1);
  st.insert(2);
  st.insert(3);
  st.insert(4);
  
  cout << "Iterate over set : ";
  for(auto i:st) cout<<i <<" ";
  cout<<endl;

  
  return 0;
}

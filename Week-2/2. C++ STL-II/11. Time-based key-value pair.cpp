/*
Problem:
Design a time-based key-value data structure that can store multiple values for the same
key at different time stamps and retrieve the key’s value at a certain timestamp.
*/

/*
Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
*/

/*
Approach for solution:

In this problem, we are asked to implement a class where the map can store multiple keys at different timestamps,
and we are asked to retrived a value for a particular key for any timestamp.

to implement this, we will create a hashmap, in which we will store key-value pairs, but the values for the keys
will be mapped to another hashmap where values for the keys at different timestamps will be stored.
Thus if asked the value of the key at a particular timestamp, we will look into the inner hashmap to find the value for
that key at that particular timestamp.

for that, we will create a hashmap where the keys are mapped to another hashmap which store values for a particular timestamp.
the hashmap will be created as:

map<string, map <int, string>> mpp;

here, suppose the key is "code" and at certain timestamps the values change as follows:
1 : enthusiast
5 : learn
8 : new

now, the hashmap will store all these values for the provided timestamps and if asked the value for that particular timestamp,
the hashmap will provide with the value which was at that time.

To get the values in the hashmap quickly, we will keep the hashmap in sorted decreasing order,
so that the newest timestamps will appear first and the oldest will appear last,
in this case the hashmap for the key "code" will look like:

hashmap(inner) = | |8|new|  |5|learn|  |1|enthusiast| | 

where the newest timestamp value 8 is appearing at the begining and the oldest value 1 is at the end and the
values are in decreasing order so that it would be easy to look up for values.

Now, suppose, a user wants to know what was the value for the key "code" at a timestamp of t= 2
In this case, we have not updated value for the key "code" at the particular timestamp 2.
But, we know that we updated the value at t=1 which was "enthusiast" and later updated the value at t=5.
So, the logical answer for this would be that the value for the key "code" is at t=1 which is "enthusiast".

To get these answers, we will use a lower_bound() function on the hashmap, since this is both in sorted and
it is in an decreasing order.
The lower_bound function will return us the first occurance if the value is present and if not present.

NOTE:
If we are applying lower_bound() on an increasing array, it gives us the value just greater than the element if not found.
If we are applying it on an increasing array, we get the value less than or equal to the given element.

So, we will apply lower_bound() over the whole hashmap for the timestamp we are looking for.
*/

//time complexity: (logN)^2
//space complexity: O(N)

//solution code (CP):

#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;


void precal(){
}


map<string, map<int, string, greater<int>>> mp;

void setter(string key, string value, int timestamp) {
    mp[key][timestamp] = value;
}    
    
string getter(string key, int timestamp) {
    if(mp.count(key)==0) return "";
    
    auto itr = mp[key].lower_bound(timestamp);
    if(itr == mp[key].end()) return "";
    return itr->second;
}
 
void solve(){
    setter("coding","ninja",1);
    setter("coding","coder",4);
    setter("coding","learning",10);
    
    setter("Competetive","Coding",3);
    setter("Competetive","learning",5);
    
    cout<<"Case#1: "<<getter("coding",0)<<"\n";
    cout<<"Case#2: "<<getter("coding",2)<<"\n";
    cout<<"Case#3: "<<getter("coding",4)<<"\n";
    cout<<"Case#4: "<<getter("coding",9)<<"\n";
    cout<<"\n";
    cout<<"Case#5: "<<getter("Competetive",1)<<"\n";
    cout<<"Case#6: "<<getter("Competetive",4)<<"\n";
    cout<<"Case#7: "<<getter("Competetive",10)<<"\n";
}   
 
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            precal();
            int t=1;
            // cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}

//solution code (DSA):

class TimeMap {
public:
        map<string, map<int, string, greater<int>>> mp;
        TimeMap(){};
    
        void set(string key, string value, int timestamp) {
            mp[key][timestamp] = value;
        }
        
        string get(string key, int timestamp) {
            if(mp.count(key) == 0) return "";

            auto it = mp[key].lower_bound(timestamp);
            if(it == mp[key].end()) return "";

            return it -> second;
        }
};


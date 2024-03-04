/*
For the game:

Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. 
If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
*/

// brute force solution

#include<bits/stdc++.h> 
using namespace std; 
  

int calculateMex(unordered_set<int> Set) { 
    int Mex = 0; 
    while (Set.find(Mex) != Set.end()) Mex++; 

    return (Mex); 
} 
  
int calculateGrundy (int n) { 
    if (n == 0) return 0; 
  
    unordered_set<int> Set; 
  
    Set.insert(calculateGrundy(n/2)); 
    Set.insert(calculateGrundy(n/3)); 
    Set.insert(calculateGrundy(n/6)); 
  
    return (calculateMex(Set)); 
} 
   
int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        cout<<calculateGrundy(n)<<"\n";
    }
    return 0;
} 


//optimized dp solution:

#include<bits/stdc++.h>
using namespace std;

//to store precomputed values
int Grundy[10000001];

int calculateMex(unordered_set<int> Set){
    int Mex = 0;
    while (Set.find(Mex) != Set.end()) Mex++;
    return Mex;
}

int calculateGrundy(int n){
    if (n == 0) return 0;
    if (Grundy[n] != -1) return Grundy[n];
    
    unordered_set<int> Set; 
    
    Set.insert(calculateGrundy(n/2));
    Set.insert(calculateGrundy(n/3));
    Set.insert(calculateGrundy(n/6));
    
    Grundy[n] = calculateMex(Set);   
    return Grundy[n];
}

int main(){
    memset(Grundy, -1, sizeof(Grundy));
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << calculateGrundy(n) << "\n";
    }
    
    return 0;
}

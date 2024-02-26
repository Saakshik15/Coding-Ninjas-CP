//Print yes if the given points are collinear, no otherwise

//code:

#include<bits/stdc++.h>
using namespace std;

bool isCollinear(int x1 , int y1 , int x2 , int y2 , int x3 , int y3){
    long long orientation = (x3 - x2) * (y2 - y1) - (y3 - y2) * (x2 - x1);
    
    if(orientation == 0) return true;
    else return false;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long x1 , y1 , x2 , y2 , x3 , y3;
        
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        
        if(isCollinear(x1 , y1 , x2 , y2 , x3 , y3)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

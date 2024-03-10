#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    string text,pattern;
    cin>>text>>pattern;

    int tn = text.size(), pn = pattern.size();

    vector<int>lps(pn);
    int j=0;
    for(int i=1;i<pn;i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j = lps[j-1];
        }
        if(pattern[i] == pattern[j]) j++;
        lps[i]=j;
    }

    vector<int>index;
    int i=0;
    j=0;
    while(i<tn){
        if(text[i] == pattern[j]){
            i++; j++;
        }else{
            if(j!=0) j=lps[j-1];
            else i++;
        }
        if(j==pn) index.push_back(i-pn);
    }

    if(index.size()==0) cout<<-1;
    else for(auto i : index) cout<<"Pattern found at index "<<i<<"\n";
}
                
int main(){
    solve();
    return 0;
}

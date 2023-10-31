/*
You are given a string s of lenght n, an array of length m consisting of lowercase characters and a positive integer k.
You can take a character from a and change any character in s with this character.
The task is to minimize the number of swaps required between s and a to make the string 'k'-periodic.

A string s is said to be k periodic if for each position i in the string s[i] = s[i+k]

eg. if s= abcabc it is a 3 periodic string
if s = aaaa is is a 1 periodic string

in one move, only one character of s can be swapped with a character of a.

the characters in a can be used more than once

all characters of k periodic string s are elements of array a.
*/

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fr(i,a,b) for(int i=a; i<b; i++)
#define loop(x,n) for(int x=0; x<n; ++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

using namespace std;

void precal(){
}
 
void solve(){


    //Taking inputs
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    vector<char>ch(m);
    for(int i=0;i<m;i++) cin>>ch[i];


    // Building a flag vector to fast check , which possible character we have to replace.
    vector<int>flag(26);
    for(int i=0;i<m;i++) flag[ch[i]-'a']=1;


    // Initalizing the freq-matrix & setting it to 0
    int freq[k][26];
    for(int i=0;i<k;i++){
        for(int j=0;j<26;j++){
            freq[i][j]=0;
        }
    }
    
    // Updating the frequency in the frequency-matrix
    for(int i=0;i<n;i++) freq[i%k][s[i]-'a']++;

    //Calculating the minimum number of changed for each
    //position in the window of size k & adding it
    int total=0;
    for(int i=0;i<k;i++){
        int maxi=0;
        int sum=0;
        for(int j=0;j<26;j++){
            sum+=freq[i][j];
            if(freq[i][j]>maxi && flag[j]==1) maxi = freq[i][j];
        }
        total+=(sum-maxi);
    }
    cout<<total<<"\n";
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
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}

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

int minSwap (int n, int m, int k, string &s, vector<char> &ch)
{
    map<char,int> al;
    for(char c: ch) al[c]++;

    int i=0, c=0;
    while(i<k){
        map<char,int> me;
        int cn=0;
        int mx=0;
        for(int j=i; j<n; j+=k){
        cn++;
        if(al.find(s[j])!=al.end()){
            me[s[j]]++;
            mx= max(mx,me[s[j]]);
        }
    }
    c+= cn-mx; 
    i++;
    }
    return c;
}

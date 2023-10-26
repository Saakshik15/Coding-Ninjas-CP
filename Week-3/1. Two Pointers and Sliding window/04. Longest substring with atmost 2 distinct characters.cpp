#include<bits/stdc++.h>

int lengthOfLongestSubstring(string str) {
   
  int n = str.size();
    int i = 0, j = 0, len = 0;
  
    unordered_map<char,int> mp;
  
    while(j < n){
        mp[str[j]]++;
      
        while(mp.size() > 2){
            mp[str[i]]--;
            if(mp[str[i]] == 0){
                mp.erase(str[i]);
            }
            i++;
        }
        len = max(len, j-i+1);
        j++;
    }
    return len;

}

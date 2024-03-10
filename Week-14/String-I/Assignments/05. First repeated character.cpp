/*
Problem statement
You are given a string 'STR' of lowercase English alphabets. You need to find the repeated character present first in the string.

Example:
If the string is: “abccba”, then the first repeated character is ‘c’, but the repeated character that is present 
first in the string is ‘a’.You need to print ‘a’.

Note:
Keep in mind that you need to print the repeated character that is present first in the string and not the first repeating character.

Constraints:
1 <= T <= 200
0 <= size of S <= 10000

where 'S’ is the string of lowercase English alphabets.

Time limit: 1 sec

Sample Input 1:
2
abccba
codingninjas

Sample Output 1:
a
i

Explanation of sample input 1:
In the first test case, 
The repeated character that occurs first in the string is ‘a’

In the second test case, 
The repeated character that occurs first in the string is ‘i’


Sample Input 2:
3
hello
helloh
abc

Sample Output 2:
l
h
%

Explanation for sample input 2:
In the first test case, 
The repeated character that occurs first in the string is ‘l’

In the second test case, 
The repeated character that occurs first in the string is ‘h’

In the third test case, 
There is no repeating character in the string, so print ‘%’
*/

//code:

#include <bits/stdc++.h>
using namespace std;

char repeatedCharacter(string str) {
  unordered_map<char, int> mp;
  for (auto ch : str)
    mp[ch]++;

  for (auto ch : str)
    if (mp[ch] > 1) return ch;

  return '%';
}


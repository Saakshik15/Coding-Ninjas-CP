//Problem: Check whether a given String 'S' is a palindrome using recursion.

//header section

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

//function to find palindrome

bool isPali(string& str, int beg, int end){
    
    if(beg == end) return true;
    if(str[beg] != str[end]) return false;
    if(beg < end+1) return isPali(str, beg+1, end-1);
}

bool isPalindrome(string& str) {
    int len = str.length();
    return isPali(str, 0, len-1);
}

//main code

class Runner{
    string t;

public:
    void takeInput(){
        cin>>t;
    }

    void execute(){
        auto ans = isPalindrome(t);
    }

    void executeAndPrintOutput(){
        auto ans = isPalindrome(t);
        ans ? cout<<"true" : cout<<"false";
    }
};

int main(){
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}


/*
Problem statement
Given a sentence(in the form of an array of words), and an integer ‘L’, return an array of strings 
i.e a paragraph such that each line has exactly ‘L’ characters, and is left and right justified.

Justification of text means that space is added between words so that both edges of each line are aligned with both margins. 
The last line in the paragraph is aligned left.

One needs to add the maximum number of words in a line such that the number of lines is minimised.

We can add whitespaces in a line so that each line has exactly the same number of characters i.e L.

If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces 
than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example:
Let the given sentence be: [ “what”, “must”, “be”, “shall”, “be.”]
And L=12.

The justified output will be :

[ “what must be”
“Shall be.”       ]

Note that the last line is only left justified.

Constraints:
1 <= T <= 100
1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <=L <= 100
words[i].length <= L

Where ‘T’ is the number of test cases, words.length denotes the number of words in the array and words[i].
length denotes the number of alphabets in each word, L denotes the number of character in each line of the result.

Time Limit: 1 sec

Sample Input 1:
2
7
This is an example of text justification.
16
3
I like apple
6

Sample Output 1:
This    is    an
example  of text
justification. 
I like
apple 

Explanation of Sample Input 1:
For the first test case, 
We have 7 words in the sentence and we can have 16 characters in each line. So we will have the output as given above.
In each line we need 16 characters, we see that the first 3 words have 4+2+2 =8 characters and add 2 gaps. 
I.e 10 characters. now if we take one more word i.e example, we exceed the total number of characters in the line 
so we can take only 3 characters. We have 8 characters and 8 spaces. Which need to be distributed between 2 gaps. 
So each gap will have 4 spaces.


For the second test case, 
We have 3 words in the sentence and 6 characters in each line. So we will have output as given above



Sample Input 2:
2
9
When there is a will there is a way
10
4
Coding ninjas is great
10

Sample Output 2:
 When there
 is  a will
 there is a
 way
 Coding    
 ninjas  is
 great    
 
*/

//code:

#include <bits/stdc++.h>

void manageWhitespaces(string& str, int& wsLength, int& wsRemain) {
    for (int i = 1; i <= wsLength; i++) str += " ";
    if (wsRemain-- > 0) str += " ";
}

string justifyText(queue<string>& q, string str, int& width, int& maxWidth) {
    int size = q.size();
    if (size == 1) size++;    // To avoid the case for divisible by zero
    
    int wsTotal = maxWidth - width + (size - 1);
    int wsLength = wsTotal / (size - 1);
    int wsRemain = wsTotal % (size - 1);
    
    while (!q.empty()) {
        if (str != "") manageWhitespaces(str, wsLength, wsRemain);
        
        str += q.front();
        q.pop();
    }
    
    return str;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    // Write your code here
    queue<string> q;
    int width = 0, ws = 0;
    
    vector<string> text;
    for (string word : words) {
        if (width + word.length() + ws <= maxWidth) {
            q.push(word);
            width += word.length() + ws;
            ws = 1;
        }
        else {
            string str = justifyText(q, "", width, maxWidth);
            text.push_back(str);
            
            q.push(word);
            width = word.length();
        }
    }
    
    if (!q.empty()) {
        string str = "";
        while (!q.empty()) {
            str += q.front() + " ";
            q.pop();
        }
        
        text.push_back(str);
    }
    
    return text;
}

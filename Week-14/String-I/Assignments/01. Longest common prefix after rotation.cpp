/*
Problem statement
You are given two strings 'A' and 'B' where string 'A' is fixed. But you can perform left shift operations 
on string B any number of times.

Your task is to find out the minimum number of left-shift operations required in order to obtain the longest 
common prefix of string 'A' and 'B'.

Note:

Left shift is defined as a single circular rotation on the string after which the first character becomes the last 
character and all other characters are shifted one index to the left.

For Example:
If A = “an”, B = “can”.
After performing one left shift operation, string B becomes “anc”.
After performing two left shift operations, string B becomes “nca”.

Follow Up:
Can you solve this in linear time and space complexity?

Constraints:
1 <= T <= 100
1 <= |A|, |B| <= 5 * 10^4
Where |A| and |B| denote the length of string, A and B respectively.   

All the characters of the string A and B contain lowercase English letters only.

Time limit: 1 second

Sample Input 1:
2
on
soon
an
an

Sample Output 1:
2
0

Explanation for sample 1:
For the first test case, the common prefix of A and B is .””
After one left shift, the string B becomes “oons”, now the common prefix is “o”.
After two left shifts, the string B becomes “onso”, now the common prefix is “on”.
After three left shifts, the string B becomes “nsoo”, now the common prefix is “”.
(We do not need to perform one more left shift, because if the number of left-shift operations is equal to the length of the string, then we get the original string. For example, here if we perform one more shift, then we get the string “soon” which was the original string.)
So after two left shifts, we get the longest common prefix i.e. “on”. Hence, the answer is 2.

For the second test case, the common prefix of A and B is “an”.
After one left shift, the string B becomes “na”, now the common prefix is “”.
So we get the longest common prefix without performing any shifts. Hence, the answer is 0. 


Sample Input 2:
2
abc 
def
sorry
personal

Sample output 2:
0
3

Explanation for sample 2:
For the first test case, the common prefix of A and B is “”.
After one left shift, the string B becomes “efd”, now the common prefix is again “”.
After two left shifts, the string B becomes “fde”, now the common prefix is again “”.
Here the length of the longest common prefix is 0, as there is no common prefix in all the cases. 
So we get the longest common prefix without performing any shifts. Hence, the answer is 0.
For the second test case, the common prefix of A and B is “”.
After one left shift, the string B becomes “ersonalp”, now the common prefix is “”.
After two left shifts, the string B becomes “rsonalpe”, now the common prefix is “”.
After three left shifts, the string B becomes “sonalper”, now the common prefix is “so”.
After four left shifts, the string B becomes “onalpers”, now the common prefix is “”.
After five left shifts, the string B becomes “nalperso”, now the common prefix is “”.
After six left shifts, the string B becomes “alperson”, now the common prefix is “”.
After seven left shifts, the string B becomes “lpersona”, now the common prefix is “”.

So after three left shifts, we get the longest common prefix i.e. “so”. Hence, the answer is 3.
*/

int minimumRequiredShifts(string a, string b){

	int ret=0, maxsame=0;

	for(int shift=0; shift<b.length(); shift++){
		for(int i=0, j=shift; i<a.length(); i++, j++){

			int k=j%b.size();
			
			if(a[i]!=b[k]) break;
			if(i+1>maxsame){
				maxsame=i+1;
				ret=shift;
			}
		}
	}
	return ret;
}

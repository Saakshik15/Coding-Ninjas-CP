/*
You’re given two strings, 'text' of length 'n' and 'pattern' of length 'm', consisting of lowercase characters.
Find all the occurrences of the string ‘pattern’ in ‘text’.

For each occurrence, print the index from where it starts in the string ‘text’ (1 - indexed).

Example:
Input: ‘text’ = “cxyzghxyzvjkxyz” and ‘pattern’ = “xyz”
Output: 2 7 13
Explanation: The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.
Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1:
cxyzghxyzvjkxyz
xyz
Sample Output 1:
3
2 7 13
Explanation Of Sample Input 1 :
The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.


Sample Input 2 :
ababacabab
aba
Sample Output 2 :
3
1 3 7
Explanation Of Sample Input 2 :
Here we have an overlap between the first occurrence (at position 1) and the second occurrence (at position 3), 
and we are considering both.

Sample Input 3 :
abcd
xy
Sample Output 3 :
0


Expected time complexity:
The expected time complexity is O(‘n’ + ‘m’).

Constraints:
1 <= ‘n’ <= 10^5
1 <= ‘m’ <= ‘n’
*/

int powllX(int a,int b, int q){
	int res = 1;
	while(b){
		if(b&1) res *= a % q;
		a *= a % q;
		b >>= 1;
	}
	return res;
}

vector<int> stringMatch(string text, string pattern) {
	vector<int> res;
	int N = text.size();
	int M = pattern.size();
	int p = 0, t = 0; // hash values for pat and text
	int q = 13; // any prime number
	int d = 256; // assume any constant
	int i,j;

	int hash = powllX(d,M-1,q); // classic power function , by using binary Exponentiation

	
	// hash values
	for(i=0;i<M;++i){
		p = (p * d + pattern[i]) % q; // calc hash values for pattern
		t = (t * d + text[i]) % q; //calc hash values for text
	}

	for(i = 0; i <= N - M; ++i){
		if(p == t){ // if window size is same
			for(j=0;j < M;++j)
				if(text[i + j] != pattern[j]) // checking characters in the window
					break;
			if (j == M) {
				res.push_back(i+1); // found the index
			}
        }
        if(i < N - M){ // if not same , then use the sliding window approach move , rolling hash algo
			t = (d * (t - text[i] * hash) + text[i + M]) % q;
			if(t < 0) t += q;
		}
	}
	return res;
}

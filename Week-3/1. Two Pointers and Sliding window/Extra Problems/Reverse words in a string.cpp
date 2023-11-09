//Problem Statement: reverse wrods in a given string provided that the string may have multiple space characters.

//code:

string reverseString(string &str){

	int n= str.length();
	int i=n-1, j=n-1;
	string ans="";

	while(j>=0){

		while(j>=0 && str[j]==' ') j--;

		if(str[j]!=' '){
			i=j;
			while(j>=0 && str[j]!=' ') j--;

			ans+= str.substr(j+1, i-j);
			ans+=' ';
		}
	}	
	return ans;
}

//time compleixty: O(n)
//space complexity: O(1)


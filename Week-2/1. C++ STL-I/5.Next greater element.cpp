/*
Problem:

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x, 
is the first greater element on right side of x in the array. Elements for which no greater element exist, consider 
next greater element as -1.

Sample Input
5
3  8  1  2  0
Sample Output
8 -1  2 -1 -1
*/

//code:

vector<int> nextGreaterElement(vector<int> input) {
	
	int n= input.size();
	vector<int> ans(n);
	stack<int> stk;

	for(int i=n-1; i>=0; i--){

		while(!stk.empty() && input[i]>=stk.top()){
			stk.pop();
		}

		if(! stk.empty()){
			ans[i]= stk.top();
		}else{
			ans[i]= -1;
		}

		stk.push(input[i]);
	}

	ans[n-1]=-1;
	return ans;
}

/*
Problem statement
Two players 'X' and 'Y', are playing a coin game. Initially, there are 'N' coins.
Each player can pick exactly 'A' coins or 'B' coins or 1 coin. A player loses the game if he is not able to pick any coins. 
'X' always starts the game, and each player plays optimally. You are supposed to find which player wins the coin game.

Constraints:
1 <= T <= 10
1 <= N <= 10^5

Time limit: 1 sec
Sample Input 1:
2
5 3 4
4 2 3
Sample Output 1:
1
0
Explanation for Sample Input 1:
For the first test case, There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. 
X picks 3 coins in the first turn, now the remaining coins are 2, Y can only pick 1 coin. So, X wins by picking the last coin.

For the second test case, No, matter what coins X picks, Y always wins.


Sample Input 2:
2
8 2 4
9 3 4
Sample Output 2:
1
0

*/

//dp solution:

bool rec(int n,int a,int b,vector<int>&dp)
{
	if (n<=0) return false;
	if (n==a || n==b || n==1) return true;
	if (dp[n]!=-1) return dp[n];
	if (n>=a && !rec(n-a,a,b,dp)) return dp[n]=1;
	if (n>=b && !rec(n-b,a,b,dp)) return dp[n]=1;
	if (n>=1 && !rec(n-1,a,b,dp)) return dp[n]=1;
	return dp[n]=0;
}

int coinGameWinner(int n, int a, int b)
{
	vector<int>dp(n+1,-1);
	return rec(n,a,b,dp);
}


//Game theory solution: 

// TODO

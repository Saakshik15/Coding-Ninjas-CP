/*
Problem statement
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. 
Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the 
last move wins the game. Can you find out who wins the game?

Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec

Sample Input 1 :
4 2 3
Sample Output 1 :
Whis

Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, 
Whis can win by removing all the remaining coins. 

*/

string findWinner(int n, int x, int y){
	int dp[n+1];
	dp[1] = 1;

	int a1 = 0, a2 = 0, a3 = 0;

	for(int i=2; i<n+1; i++){
		if(i == x || i == y){
			dp[i] = 1;
			continue;
		}

		if(i-x >= 1) a1 = dp[i-x] ^ 1;
		if(i-y >= 1) a2 = dp[i-y] ^ 1;
		a3 = dp[i-1] ^ 1;

		dp[i] = max(a1, max(a2 ,a3));
	}

	if(dp[n] != 0) return "Beerus";
	else return "Whis";
}

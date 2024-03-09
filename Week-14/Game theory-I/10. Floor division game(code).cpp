/*
Problem statement
Jack and Michael are waiting in a room, eager to join the CodeKaze elimination Round. They decide to pass the time by playing a game.

In this game's setup, they write ‘N’ positive integers on a blackboard. Then the players take turns, starting with Jack. 
In one turn, a player selects one of the integers, divides it by 2, 3, 4, 5 or 6, and then takes the floor to make it an integer again. 
If the integer becomes 0, it is erased from the board. The player who makes the last move wins.

Jack and Michael are very competitive, so aside from wanting to win CodeKaze, they also want to win this game. 
Assuming they play with the optimal strategy, your task is to predict who wins the game.

For example:

Let A = [1, 1, 2]. If Jack selects the third element and divide it by ‘3’ and remove it, then the new array will look like 
A = [1, 1], Now, if Michael selects the second element and divides it by ‘3’, it will delete the element, and the new array will 
look like A = [1]. Now, Jack selects the only element and divides it by '2', removes it and wins the game.

Constraints -
1 ≤ T ≤ 1000
1 ≤ N ≤ 100
1 ≤ A[i] ≤ 10^18, for 1 <= i <= ‘N’


Time Limit: 1 sec


Sample Input-1
2
2
3 4
3
1 3 5
Sample Output-1
Jack
Michael
Explanation for Sample Input 1:
For test case 1:
    Jack can select ‘4’ and divide by ‘2’. Now the new array looks like [3, 2].
    Michael can select ‘2’ and divide by ‘3’ and remove the number. Now the new array looks like [3].
    Jack can select ‘3’ and divide by ‘6’ and remove the number.
    Jack wins the game( Jack will always win if he divides the number ‘4’ by ‘2’).
For test case 2:
    Jack can select ‘3’ and divide by ‘2’. Now the new array looks like [1, 1, 5].
    Michael can select ‘5’ and divide by ‘6’ and remove the number. Now the new array looks like [1, 1].
    Jack can select ‘1’ and divide by ‘2’ and remove the number. Now the array looks like [1].
    Michael can select '1' and divide it by '2' and remove it. Michael wins the game.
Note that this is one of the possible ways of playing the game.


Sample Input-2
2
3 
1 5 7
3
3 3 3
Sample Output-
Jack
Jack
*/


string game(int n, vector<long long> a){

	vector<int> g = {0,1,2,2,3,3,0,0,0,0,0,0};

	int res = 0;
		for(int i=0; i<n; i++) {
			while(a[i] >= 12) {
				a[i] /= 12;
			}
			res ^= g[a[i]];
		}
		if(res == 0) return "Michael";
		else return "Jack";
}

/*
Problem statement
Game of Nim Rules :

1. Given a number of piles,each pile contains some numbers of stones. 
2. The players take alternate turns. If the bitwise XOR of all piles equals 0 before a player's turn, then that player wins the game.
3. In his/her turn, a player must choose one of the remaining piles and remove it. 
  (Note that if there are no piles, that player already won.)
Decide which player wins, given that both play optimally.

Constraints :
1 ≤ N ≤ 1000
1 ≤ ai ≤ 1000

Sample Input 1:
3
2 3 1
Sample Output 1:
First

Sample Input 2:
3 
2 3 3
Sample Output 2:
second
*/

void findWinner(int *arr, int n) {
    int nimSum = 0;
    for (int i = 0; i < n; ++i) nimSum ^= arr[i];

    if (nim_sum == 0 || n % 2 == 0) cout << "First" << endl;
	  else cout << "Second" << endl;
}

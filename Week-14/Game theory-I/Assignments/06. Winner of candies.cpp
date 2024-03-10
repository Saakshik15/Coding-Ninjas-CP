/*
Problem statement
You and your friend met after a long time and decided to have candies. You brought ‘X’ candies while your friend brought ‘Y’ candies. 
Since you both were bored you decided to play a game where each of you will play one by one and you will start first. 

The game goes as follows :
In the ith move, the person will give i candies to the other person.
The person who is unable to donate the required amount of candies will lose. You are required to find out who will win the game.

For Example:
For X = 1, Y = 2 the game goes as follows - 
You will donate 1 candy. So you now have 0 and your friend has 3 candies.
Your friend will donate 2 candies. So you now have 2 and your friend has 1 candy.
You are required to donate 3 candies but you only have 2 candies.
Hence your friend wins.

Constraints:
1 <= T <= 100
1 <= X, Y <= 10^9

Time Limit: 1 sec.

Sample Input 1:
1
3 2

Sample Output 1:
Win

Sample Input 2:
1
100 1

Sample Output 2:
Win
*/

//code:

string winnerOfCandies(int x, int y) {
  int round = 1;

  while(x >= 0 and y >= 0) {
      
    if (round % 2 != 0) {
      x -= round; y += round;
    } else {
      x += round; y -= round;
    }
    round++;
  }
  return x < 0 ? "Lose" : "Win";
}

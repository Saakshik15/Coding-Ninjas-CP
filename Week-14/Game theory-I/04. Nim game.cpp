/*
The Game of Nim is described by the following rules- 

“ Given a number of piles in which each pile contains some numbers of stones/coins. 
In each turn, a player can choose only one pile and remove any number of stones (at least one) from that pile. 
The player who cannot move is considered to lose the game (i.e., one who take the last stone is the winner). ”
*/

/*
we can conclude that this game depends on two factors-

The player who starts first.
The initial configuration of the piles/heaps.


we can predict the winner of the game by-Nim-Sum : 
The cumulative XOR value of the number of coins/stones in each piles/heaps at any point of the game is called Nim-Sum at that point. 
“If both A and B play optimally (i.e- they don’t make any mistakes), then the player starting first is guaranteed to win if the Nim-Sum 
at the beginning of the game is non-zero. Otherwise, if the Nim-Sum evaluates to zero, then player A will lose definitely.” 

Optimal Strategy :

If the XOR sum of ‘n’ numbers is already zero then there is no possibility to make the XOR sum zero by single reduction of a number.
If the XOR sum of ‘n’ numbers is non-zero then there is at least a single approach by which if you reduce a number, the XOR sum is zero.

Initially, there are two cases:

Case 1: Initial Nim Sum is zero As we know, in this case if played optimally B wins, 
which means B would always prefer to have Nim sum of zero for A‘s turn. So, as the Nim Sum is initially zero, 
whatever number of items A removes the new Nim Sum would be non-zero (as mentioned above). Also, as B would 
prefer Nim sum of zero for A‘s turn, he would then play a move so as to make the Nim Sum zero again (which is 
always possible, as mentioned above). The game will run as long as there are items in any of the piles and in 
each of their respective turns A would make Nim sum non-zero and B would make it zero again and eventually there 
will be no elements left and B being the one to pick the last wins the game. It is evident by above explanation 
that the optimal strategy for each player is to make the Nim Sum for his opponent zero in each of their turn, 
which will not be possible if it’s already zero.


Case 2: Initial Nim Sum is non-zero Now going by the optimal approach A would make the Nim Sum to be zero now 
(which is possible as the initial Nim sum is non-zero, as mentioned above). Now, in B‘s turn as the nim sum is
already zero whatever number B picks, the nim sum would be non-zero and A can pick a number to make the nim sum 
zero again. This will go as long as there are items available in any pile. And A will be the one to pick the last item. 
So, as discussed in the above cases, it should be obvious now that Optimal strategy for any player is to make the nim sum 
zero if it’s non-zero and if it is already zero then whatever moves the player makes now, it can be countered.
*/


int ninjaGame(vector<int> &a, int n) {
    int XOR=0;
    for(int i=0; i<n; i++) XOR ^= a[i];

    return XOR!=0; 
    //return 1 if player 1 wins, 0 otherwise
}


//

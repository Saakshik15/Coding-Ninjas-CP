/*
Grundy Number:
Grundy Number is a number that defines a state of a game. 
We can define any impartial game (example : nim game) in terms of Grundy Number.

Grundy Numbers or Numbers determine how any Impartial Game (not only the Game of Nim) 
can be solved once we have calculated the Grundy Numbers associated with that game using Sprague-Grundy Theorem.

What is Mex? 
‘Minimum excludant’ a.k.a ‘Mex’ of a set of numbers is the smallest non-negative number not present in the set. 

Given a set s, the smallest number >= 0 (greater than equal to 0) that is not present in the set s.

mex(phi) =0
mex({0}) =1
mex({0,1,2}) =3
mex({0,2}) =1

How to calculate Grundy Numbers? 
We use this definition- The Grundy Number/ number is equal to 0 for a game that is lost immediately by the first 
player and is equal to Mex of the numbers of all possible next positions for any other game.
*/

/*
Example 1 :

The game starts with a pile of n stones, and the player to move may take any positive number of stones. 
Calculate the Grundy Numbers for this game. The last player to move wins. Which player wins the game?

if the first player has 0 stones, he will lose immediately, so 
Grundy(0) = 0

If a player has 1 stones, then he can take all the stones and win. 
So the next possible position of the game (for the other player) is (0) stones
Grundy(1) = Mex(0) = 1 .....[According to the definition of Mex]

If a player has 2 stones, then he can take only 1 stone or he can take all the stones and wins. 
So the next possible position of the game (for the other player) is (1, 0) stones respectively.
Grundy(2) = Mex(0, 1) = 2 .....[According to the definition of Mex]

Similarly, If a player has ‘n’ stones, then he can take only 1 stone, or he can take 2 stones…….. 
or he can take all the stones and win. So the next possible position of the game (for the other player) is 
(n-1, n-2,….1) stones respectively.
Hence, Grundy(n) = Mex (0, 1, 2, ….n-1) = n .....[According to the definition of Mex] 
*/


//Implementation code of grundy numbers : 
/*
For the game:
The game starts with a pile of n stones, and the player to move may take any positive number of stones up to 3 only. 
The last player to move wins. Which player wins the game? This game is 1 pile version of Nim.
*/

#include<bits/stdc++.h>

using namespace std;

int mex(multiset<int> &vals){
	int MEX = 0;
	while(vals.find(MEX) != vals.end()){
		MEX++;
	}
	return MEX;
}

int main() {
	int n = 10;

	int grundy[n+1];

	multiset<int> vals;

	for(int i=0; i<=3; i++) {
		grundy[i] = i;
		vals.insert(i);
	}

	for(int i=4; i<=n; i++) {
		vals.erase(vals.find(grundy[i-4]));
		grundy[i] = mex(vals);
		vals.insert(grundy[i]);
	}

	for(int i=0; i<=n; i++) cout<<grundy[i]<<" ";

	return 0;
}




Consider a Nim game where each player has to choose stones from the given 3 piles.
And each player can choose anywhere between stones 1 to 3.

Consider the three pile of stones are 4, 5, 6
Then, we can consider pile 1 with 4 stones as subgame 1, S1
similarly, pile 2 with 5 stones as subgame 2, S2
similarly, pile 3 with 6 stones as subgame 3, S3

then, according to Sprague Grundy theorem, a player can win the game if and only if,
  Grundy(4) ^ Grundy(5) ^ Grundy(6) > 0
  and if it is =0, then player will lose the game.

Grundy numbers for this game are:

Grundy : 0 1 2 3 0 1 2 3
No.    : 0 1 2 3 4 5 6 7

So, determining if player starting can win the game:
Grundy(4) ^ Grundy(5) ^ Grundy(6) = 0^1^2 = 3

  So, in conclusion, player starting the game will win the game.

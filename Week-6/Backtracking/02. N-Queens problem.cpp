/*
We can only place 1 queen in each row, col and diagonal.
Also, before placing any Queen we can check if it is safe to place a Queen-
By checking that the current Queen is not attacking any other previously placed queens.
If the current placed queen attacks, we will check for any further state or if not possible then backtrack.
*/

//pseudo-code for isValid function:

bool isValid(board,x,y){
  if (no 2 queens on same row &&
      no 2 queens on the same column &&
      no 2 queens on the same diagonal) 
    return true;
  else 
    return false;
}


// NQueen function pseudo-code:

NQueen(board, col, n, ans){
  if (col==n) {
    push board in ans;
    return;
  }

  for(int i=0; i<n; i++){
    if(isValid(board,i, col)) 
      board[i][col]=1;
    
    NQueen(board, col+1, n, ans);
    board[i][col]=0;
  }
}

// time complexity: O(n!)
// space compleixty: O(n^2) + O(n) for calling stack

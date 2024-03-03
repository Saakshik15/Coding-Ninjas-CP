// possible moves:
/*
	x-1, y-2
	x+1, y-2
	x-2, y-1
	x-2, y+1
*/

#include<bits/stdc++.h>
using namespace std;

int grid[16][16];

bool valid(int x, int y) {
	if(x<=0 or y<=0 or x>15 or y>15) {
		return false;
	}
	return true;
}

int f(int x, int y) {
	if(grid[x][y] != -1) return grid[x][y];

	else {
		bool isWin = false;
		if(valid(x-1, y-2)) {
			if(f(x-1, y-2) == 0) isWin = true;
		}

		if(valid(x+1, y-2)) {
			if(f(x+1, y-2) == 0) isWin = true;
		}

		if(valid(x-2, y-1)) {
			if(f(x-2, y-1) == 0) isWin = true;
		}

		if(valid(x-2, y+1)){
			if(f(x-2, y+1) == 0) isWin = true;
		}

		if(isWin) grid[x][y] = 1;
		else grid[x][y] = 0;
		return grid[x][y];
	}
}


int main() {
  
	int t;
	cin>>t;
	while(t--) {
		int x, y;
		cin>>x>>y;
		for(int i=0; i<=15; i++) {
			for(int j=0; j<=15; j++) {
				grid[i][j] = -1;
			}
		}

		grid[1][1] = grid[1][2] = grid[2][1] = grid[2][2] = 0;
		if(f(x, y) == 0) cout<<"Second\n";
		else cout<<"First\n";
	}
	return 0;
}

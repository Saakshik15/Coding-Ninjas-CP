// link: https://www.codingninjas.com/studio/problems/chessboad-game_3210621?leftPanelTabValue=PROBLEM

bool isValid(int x, int y){
    return x >= 0 && x < 15 && y >= 0 && y < 15;
}

bool isWinning(int x, int y, vector<vector<int>> &dp, vector<int> &dx, vector<int> &dy){
    if (dp[x][y] != -1)
        return dp[x][y];
    
    dp[x][y] = 0;
    for (int i = 0; i < 4; ++i){
        if (isValid(x + dx[i], y + dy[i]) && !isWinning(x + dx[i], y + dy[i], dp, dx, dy)){
            dp[x][y] = 1;
            break;
        }
    }
    return dp[x][y];
}

string winnerOfGame(int x, int y){
    x--, y--;

    vector<vector<int>> dp(15, vector<int>(15));
    for (int i = 0; i < 15; ++i){
        for (int j = 0; j < 15; ++j)
            dp[i][j] = -1;
    }

    vector<int> dx = {-2, -2, 1, -1};
    vector<int> dy = {1, -1, -2, -2};

    if (isWinning(x, y, dp, dx, dy)) return "First";
    else return "Second";
}

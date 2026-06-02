class Solution {
public:
    int path(int up, int left, vector<vector<int>>&dp){
        if(up == 0 && left == 0) return 1;
        if(up < 0 || left < 0) return 0;
        if(dp[up][left] != -1) return dp[up][left];
        int right = path(up,left-1, dp);
        int down = path(up-1, left, dp);
        return dp[up][left] = right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return path(m-1, n-1, dp);
    }
};

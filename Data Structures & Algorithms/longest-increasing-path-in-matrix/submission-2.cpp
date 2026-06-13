class Solution {
public:
    int dfs(int r, int c, int prevVal, vector<vector<int>>&matrix, vector<vector<int>>&dp, vector<vector<int>>&direction){
        int row = matrix.size(), col = matrix[0].size();
        if(r<0 || r>=row || c<0 || c>= col || matrix[r][c] <= prevVal){return 0;}
        if(dp[r][c]!=-1) return dp[r][c];
        int res = 1;
        for(vector<int>d :direction){
            res = max(res, 1+dfs(r+d[0], c+d[1],matrix[r][c],matrix, dp, direction));
        }
        dp[r][c] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>>dp(row, vector<int>(col, -1));
        int lip = 0;
        vector<vector<int>>direction={{-1,0}, {1,0}, {0,-1}, {0,+1}};
        for(int r=0; r<row; r++){
            for(int c = 0; c<col; c++){
                lip = max(lip, dfs(r,c, INT_MIN, matrix, dp, direction));
            }
        }
        return lip;
    }
};

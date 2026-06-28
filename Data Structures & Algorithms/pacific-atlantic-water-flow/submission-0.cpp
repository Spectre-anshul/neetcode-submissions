class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>&heights, vector<vector<int>>&directions){
        int m = heights.size(), n = heights[0].size();
        ocean[r][c] = true;
        for(int i=0; i<4; i++){
            int row = r+directions[i][0];
            int col = c+directions[i][1];
            if(row>=0 && row<m && col>=0 && col<n && !ocean[row][col] && heights[row][col]>=heights[r][c]){
                dfs(row, col, ocean, heights, directions);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>>pac(m, vector<bool>(n, false));
        vector<vector<bool>>atl(m, vector<bool>(n,false));
        vector<vector<int>>directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        for(int c=0; c<n; c++){
            dfs(0, c, pac, heights, directions);
            dfs(m-1,c, atl, heights, directions);
        }
        for(int r=0; r<m; r++){
            dfs(r, 0, pac, heights, directions);
            dfs(r, n-1, atl, heights, directions);
        }
        vector<vector<int>>res;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};

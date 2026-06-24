class Solution{
    public:
    void islandsAndTreasure(vector<vector<int>>&grid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        vector<vector<int>>direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
        int row = q.front().first, col = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int r = row + direction[i][0], c = col + direction[i][1];
            if(r<0 || r>=m || c<0 || c>=n || grid[r][c]!=INT_MAX) continue;
            grid[r][c] = grid[row][col]+1;
            q.push({r,c});
        }
        }
    }
};
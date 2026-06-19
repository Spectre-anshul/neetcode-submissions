class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&directions){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int area = 1;
        for(int i=0; i<4; i++){
            area+=dfs(r+directions[i][0], c+directions[i][1], grid, directions);
        }  
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int row = grid.size(), col = grid[0].size();
        int maxi = 0;
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 1){
                    int size = dfs(r,c, grid, directions);
                    maxi = max(maxi, size);
                }
            }
        }
        return maxi;
    }
};

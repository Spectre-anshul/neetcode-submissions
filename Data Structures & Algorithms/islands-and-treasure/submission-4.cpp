class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        vector<vector<int>>direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int d = 0; d<4; d++){
                int i = direction[d][0] + r;
                int j = direction[d][1] + c;
                if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j] != INT_MAX) continue;
                grid[i][j] = 1+ grid[r][c];
                q.push({i,j});
            }
        }
    }
};

class Solution {
public:
vector<vector<int>>direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int d =0; d<4; d++){
                int r = i + direction[d][0];
                int c = j + direction[d][1];
                if(r>=0 && c>=0 && r<grid.size() && c < grid[0].size() && grid[r][c] == INT_MAX){
                    grid[r][c] = 1+grid[i][j];
                    q.push({r,c});
                }
            }
        }
    }
};

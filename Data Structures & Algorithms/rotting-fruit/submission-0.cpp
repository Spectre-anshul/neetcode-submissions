class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 2)
                    q.push({{i,j},0});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        int time = 0;

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int t = curr.second;

            time = max(time,t);

            for(auto &d : dir){

                int r = row + d.first;
                int c = col + d.second;

                if(r<0 || r>=m || c<0 || c>=n)
                    continue;

                if(grid[r][c] != 1)
                    continue;

                grid[r][c] = 2;
                fresh--;

                q.push({{r,c}, t+1});
            }
        }

        return fresh == 0 ? time : -1;
    }
};

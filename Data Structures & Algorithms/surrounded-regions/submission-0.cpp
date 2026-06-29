class Solution{
    public:
    void solve(vector<vector<char>>&board){
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>>q;
        //securing all the boarder 'O'
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') {q.push({i,0});
            board[i][0] = '#';}
        }
        for(int i=0; i<n; i++){
            if(board[0][i] == 'O'){ q.push({0,i});
            board[0][i] = '#';}
        }
        for(int i=0; i<m; i++){
            if(board[i][n-1] == 'O'){ q.push({i, n-1});
            board[i][n-1] = '#';}
        }
        for(int i=0; i<n; i++){
            if(board[m-1][i] == 'O'){ q.push({m-1, i});
            board[m-1][i] = '#';}
        }
        vector<vector<int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        //securing all the areas connected to the boundary----
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int row = r+directions[i][0], col = c+directions[i][1];
                if(row < 0 || row>=m || col < 0 || col >= n || board[row][col] != 'O') continue;
                board[row][col] = '#';
                q.push({row, col}); 
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        return;
    }
};
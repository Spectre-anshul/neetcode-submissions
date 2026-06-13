class Solution{
    public:
    int dfs(int i, int j, vector<vector<int>>&dp, string &s, string &t){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int res = dfs(i+1, j, dp, s, t);
        if(s[i] == t[j]){
            res += dfs(i+1, j+1, dp, s, t);
        }
        dp[i][j] = res;
        return res;
    }
    int numDistinct(string s, string t){
        int si = s.size(), ti = t.size();
        if(ti > si) return 0;
        vector<vector<int>>dp(si, vector<int>(ti+1, -1));
        return dfs(0,0, dp, s, t);
    }
};
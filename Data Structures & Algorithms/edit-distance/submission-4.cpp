//brute force ---- takes care of 50% of the problems ------
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         if(n!=m) return n-m;
        
//         int count = 0;
//         for(int i=0; i<n; i++){
//             if(word1[i] != word2[i]) count++;
//         }
//         return count;
//         }
// };


class Solution{
    public:
    int dfs(int i, int j, string &word1, string &word2, vector<vector<int>>&dp){
        int m = word1.size(), n = word2.size();
        if(i == m) return n-j;
        if(j == n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if (word1[i] == word2[j]){
            dp[i][j] = dfs(i + 1, j + 1, word1, word2, dp);
        } else {
            int res = min(dfs(i + 1, j, word1, word2, dp),dfs(i, j + 1, word1, word2, dp));
            res = min(res, dfs(i + 1, j + 1, word1, word2, dp));
            dp[i][j] = res + 1;
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2){
        int n = word1.size(), m= word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return dfs(0, 0, word1, word2, dp);
    }
};

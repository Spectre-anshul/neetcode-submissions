// total brute forcce doesnt work if your sequence is wrong -----
// ""class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         sort(text1.begin(), text1.end());
//         sort(text2.begin(), text2.end());
//         int cnt = 0;
//         for(int i=0; i<text1.size(); i++){
//             for(int j=0; j<text2.size(); j++){
//                 if(text1[i] == text2[j]) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution{
    public:
    int solve(string text1, string text2,int n, int m, vector<vector<int>>&dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(text1[n] == text2[m]){
            dp[n][m] = 1+ solve(text1, text2, n-1, m-1, dp);
        }
        else{
            dp[n][m] = max(solve(text1, text2, n-1, m, dp), solve(text1, text2, n, m-1, dp));
        }
        return dp[n][m];


    }
    int longestCommonSubsequence(string text1, string text2){
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(text1, text2,n-1, m-1, dp);
    }
};
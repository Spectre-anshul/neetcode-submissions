// class Solution {
// public:
//     bool recursion(int i, int j, int k, string s1, string s2, string s3){
//         if(k == s3.size()){
//             return (i==s1.size() && j == s2.size());
//         }
//         if(i<s1.size() && s1[i] == s3[k]){
//             if(recursion(i+1, j, k+1, s1,s2,s3)){
//                 return true;
//             }
//         }
//         if(i<s2.size() && s2[j] == s3[k]){
//             if(recursion(i, j+1, k+1, s1,s2,s3)){
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         return recursion(0,0,0, s1, s2, s3);
//     }
// };


class Solution{
    public:
    bool interleave(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>&dp){
        if(k == s3.size()){
            return (i==s1.size() && j == s2.size());
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if(i<s1.size() && s1[i] == s3[k]){
            res = interleave(i+1, j, k+1, s1, s2, s3,dp);
        }
        if(j<s2.size() && s2[j] == s3[k]){
            res = interleave(i, j+1, k+1, s1, s2, s3,dp);
        }
        dp[i][j] = res;
        return res;
    }
    bool isInterleave(string s1, string s2, string s3){
        int i = s1.size(), j = s2.size();
        if(i+j != s3.size()) return false;
        vector<vector<int>>dp(i+1, vector<int>(j+1, -1));
        return interleave(0,0,0, s1,s2,s3,dp);
    }
};

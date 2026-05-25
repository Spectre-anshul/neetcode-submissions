// class Solution {
// public:
// int dfs(int i, string &s){
//     if(i == s.size()) return 1;
//     if(s[i]=='0') return 0;
//     int res = dfs(i+1, s);
//     if(i<s.size()-1){
//         if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7')){
//             res += dfs(i+2, s);
//         }
//     }
//     return res;
// }
//     int numDecodings(string s) {
//         return dfs(0, s);
//     }
// };


// class Solution{
//     public:
//     int dfs(int i, string s, vector<int>dp){
//         if(i == s.size()) return 1;
//         if(s[i] == '0') return 0;
//         if(dp[i]!= -1) return dp[i];
//         int res = dfs(i+1, s, dp);
//         if(i+1 < s.size()){
//             if(i < s.size()-1){
//                 if(s[i]== '1' || (s[i]== '2' && s[i+1]<'7')){
//                     res += dfs(i+2, s, dp);
//                 }
//             }
//         }
//         return dp[i] = res;
//     }
//     int numDecodings(string s){
//         int n = s.size();
//         vector<int>dp(n, -1);
//         return dfs(0, s, dp);
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }

private:
    int dfs(string s, int i, unordered_map<int, int>& dp) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' ||
            s[i] == '2' && s[i + 1] < '7')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }
};

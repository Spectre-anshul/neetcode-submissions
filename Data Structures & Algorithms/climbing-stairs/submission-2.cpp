class Solution {
public:
    int climb(vector<int>&dp, int n){
        if(n<=1) return 1;
        if(dp[n]!=0) return dp[n];
        dp[n] = climb(dp,n-1) + climb(dp, n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        return climb(dp, n);        
    }
};

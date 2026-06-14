class Solution {
public:
    int dfs(int l, int r, vector<vector<int>>&dp, vector<int>&memo){
        if(l>r) return 0;
        if(dp[l][r]!= -1) return dp[l][r];
        dp[l][r] = 0;
        for(int i=l; i<=r; i++){
            int coins = memo[l-1]*memo[i]*memo[r+1];
            coins += dfs(l, i-1, dp, memo) + dfs(i+1, r, dp, memo);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n+2, 1);
        for(int i=0; i<n; i++){
            memo[i+1] = nums[i];
        }
        vector<vector<int>>dp(n+2, vector<int>(n+2,-1));
        return dfs(1, memo.size()-2, dp, memo);
    }
};

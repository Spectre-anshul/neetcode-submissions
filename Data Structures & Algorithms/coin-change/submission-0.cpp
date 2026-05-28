class Solution {
public:
int bfs(int amount, vector<int>&coins, vector<int>&dp){
    if(amount == 0) return 0;
    if(amount < 0) return -1;
    if(dp[amount]!= -2) return dp[amount];
    int mini = INT_MAX;
    for(auto coin:coins){
        int res = bfs(amount - coin, coins, dp);
        if(res >= 0 && res < mini){
            mini = res+1;
        }
    }
    return dp[amount] = (mini == INT_MAX)? -1: mini;

}
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -2);
        return bfs(amount, coins, dp);
    }
};

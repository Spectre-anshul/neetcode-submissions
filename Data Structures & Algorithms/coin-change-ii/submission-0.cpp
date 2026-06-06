class Solution {
public:
int total(int ind, int amount, vector<vector<int>>&dp, vector<int>&coins){
    if(ind == 0){
        return (amount % coins[0] == 0);
    }
    if(dp[ind][amount]!=-1)return dp[ind][amount];
    int nottake = total(ind-1, amount, dp, coins);
    int take=0;
    if(coins[ind] <= amount){
        take = total(ind, amount-coins[ind], dp, coins);
    }
    return dp[ind][amount] = nottake + take;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return total(n-1, amount, dp, coins);
    }
};
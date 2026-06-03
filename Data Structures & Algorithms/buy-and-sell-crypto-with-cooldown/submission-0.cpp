class Solution {
public:
    int profit(int day, int buy, vector<vector<int>>&dp, vector<int>&prices){
        if(day >= prices.size()) return 0;
        if(dp[day][buy]!= -1) return dp[day][buy];
        int cooldown = profit(day+1, buy, dp, prices);
        if(buy){
            int buyin = profit(day+1, 0, dp, prices) - prices[day];
            dp[day][buy] = max(buyin, cooldown);
        }
        else{
            int sellin = profit(day+2, 1, dp, prices) + prices[day];
            dp[day][buy] = max(sellin, cooldown);
        }
        return dp[day][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return profit(0, 1, dp, prices);
    }
};

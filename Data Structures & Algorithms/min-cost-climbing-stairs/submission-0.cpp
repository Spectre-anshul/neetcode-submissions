class Solution {
public:
int costy(int n, vector<int>&dp, vector<int>&cost){
  if(n <= 1) return 0;
  if(dp[n] != -1) return dp[n];
  int one = costy(n-1, dp, cost) + cost[n-1];
  int two = costy(n-2, dp, cost) + cost[n-2];
  return dp[n] = min(one, two);
  
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1,-1);
        return costy(n, dp, cost);
    }
};

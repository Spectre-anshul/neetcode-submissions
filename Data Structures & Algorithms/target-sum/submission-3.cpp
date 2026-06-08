class Solution{
    public:
    int sumway(int i, int sum, int total, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(i == nums.size()) return (sum == target);
        if(dp[i][sum + total]!= -1) return dp[i][sum+total];
        return dp[i][sum+total] = sumway(i+1, sum+nums[i], total, nums, target, dp) +sumway(i+1, sum-nums[i], total, nums, target, dp);
    }
    int findTargetSumWays(vector<int>&nums, int target){
        int total=0;
        for(auto i: nums){
            total+=i;
        }
        int n = nums.size();
        if(abs(target) > total)
            return 0;
        vector<vector<int>>dp(n, vector<int>(2*total + 1, -1));
        return sumway(0, 0, total, nums, target, dp);
    }
};
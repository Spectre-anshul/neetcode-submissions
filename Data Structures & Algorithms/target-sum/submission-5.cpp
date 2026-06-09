class Solution{
    public:
    int sumway(int i, int sum, int totalsum, int target, vector<vector<int>>&dp, vector<int>&nums){
        if(i == nums.size()) return(sum == target);
        if(dp[i][sum + totalsum] != -1) return dp[i][sum + totalsum];
        return dp[i][sum + totalsum] = sumway(i+1, sum + nums[i], totalsum, target, dp, nums)+ sumway(i+1, sum-nums[i], totalsum, target, dp, nums);
    }
    int findTargetSumWays(vector<int>&nums, int target){
        int totalsum = 0;
        for(auto i: nums){
            totalsum+=i;
        }
        if(target > totalsum)return 0;
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2*totalsum + 1, -1));
        return sumway(0,0, totalsum, target, dp, nums);
    }
};
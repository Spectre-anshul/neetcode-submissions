class Solution{
    public:
    bool solve(int ind, int target, vector<vector<int>>&dp, vector<int>&nums){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        if(dp[ind][target]!= -1) return  dp[ind][target];
        bool nopick = solve(ind-1, target, dp, nums);
        bool yes = false;
        if(nums[ind] <= target){
            yes = solve(ind-1, target - nums[ind], dp, nums);
        } 
        return dp[ind][target] = yes||nopick;
    }
    bool canPartition(vector<int>&nums){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n;i++){
            sum+=nums[i];
        }
        int k = 0;
        if(sum %2 == 1) return false; //odd sum cannot be partitioned
        else k = sum /2;
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        return solve(n-1, k, dp, nums);
    }
};
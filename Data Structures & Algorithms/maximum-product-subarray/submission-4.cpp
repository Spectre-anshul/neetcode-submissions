// class Solution {
// public:
//     int product(int n, vector<int>&dp, vector<int>&nums){
//         if(n==0) return ;
//         if(n<0) return -1;
//         if(dp[n]!=-1) return dp[n];
//         int product = INT_MIN;
//         return dp[n] = max((product(n-1,dp, nums) * product(n-2,dp, nums)), product(n, dp, nums));
//     }
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n+1, -1);
//         return product(n, dp, nums);
//     }
// };

class Solution{
    public:
    int maxProduct(vector<int>&nums){
        int res = nums[0];
        int curMin = 1, curMax = 1;
        for(int num: nums){
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num*curMin), num);
            curMin = min(min(tmp, num*curMin), num);
            res = max(res, curMax);
        }
        return res;

    }
};
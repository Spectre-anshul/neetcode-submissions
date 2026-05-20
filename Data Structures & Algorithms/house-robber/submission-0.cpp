class Solution {
public:
int roob(int n, vector<int>&dp, vector<int>&nums){
  if(n<0)return 0;
  if(n==0)return nums[0];
  if(dp[n]!= -1)return dp[n];
  int take = roob(n-2, dp, nums)+ nums[n];
  int nottake = roob(n-1, dp, nums);
  return dp[n] = max(take, nottake);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return roob(n - 1, dp, nums);
    }
};
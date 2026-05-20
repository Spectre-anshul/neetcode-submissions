class Solution {
public:
int roob(int start, int n, vector<int>&dp, vector<int>&nums){
  if(n<start)return 0;
  if(n == start) return nums[start];
  if(dp[n]!=-1)return dp[n];
  int take = nums[n] + roob(start, n-2, dp, nums);
  int nottake = roob(start, n-1, dp, nums);
  return dp[n] = max(take, nottake);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        int ans1 = roob(0, n-2, dp1, nums);
        int ans2 = roob(1, n-1, dp2, nums);
        return max(ans1, ans2);
    }
};
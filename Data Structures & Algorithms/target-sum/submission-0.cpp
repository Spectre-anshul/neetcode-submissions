class Solution {
public:

    unordered_map<string, int> dp;

    int solve(int i,
              int sum,
              vector<int>& nums,
              int target) {

        if(i == nums.size()) {
            return (sum == target);
        }

        string key =
            to_string(i) + "," + to_string(sum);

        if(dp.count(key))
            return dp[key];

        int plus =
            solve(i + 1,
                  sum + nums[i],
                  nums,
                  target);

        int minus =
            solve(i + 1,
                  sum - nums[i],
                  nums,
                  target);

        return dp[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(0, 0, nums, target);
    }
};

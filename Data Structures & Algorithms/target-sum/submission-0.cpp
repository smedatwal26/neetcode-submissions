class Solution {
public:
    int offset = 1000;
    int dfs(vector<int>& nums, int target,int i, vector<vector<int>> &dp,int sum){
        if(target == sum && i==nums.size()){
        return 1;
        }
        if(i>=nums.size())
        return 0;
        if(dp[i][sum+offset]!=-1)
        return dp[i][sum+offset];
        int res = 0;
        res = dfs(nums,target,i+1,dp,sum+nums[i]);
        res+= dfs(nums,target,i+1,dp,sum-nums[i]);
        dp[i][sum+offset] = res;
        return res;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (2000+1,-1));
         return dfs(nums,target,0,dp,0);
    }
};

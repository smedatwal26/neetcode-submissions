class Solution {
public:
    int dfs(vector<int> nums, vector<int> &dp,int i){
        if(dp[i] != -1){
            return dp[i];
        }
        int res = 1;
        for(int j = i+1;j<nums.size(); j++){
            if(nums[i] < nums[j])
            res = max(res,1 + dfs(nums,dp,j));
        }
        dp[i] = res;
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
         vector<int> dp(nums.size(),-1);
         int res = 1;
         for(int i=0;i<nums.size();i++){
            res = max(res,dfs(nums,dp,i));
         }
         return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() ==1)
        return nums[0];
        vector<int> num1(nums.begin() + 1 , nums.end());
        vector<int> num2(nums.begin() , nums.end() - 1);
           return max(help(num1),help(num2));
    }
    int help(vector<int> nums){
        if(nums.size() == 1)
        return nums[0];
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }

};

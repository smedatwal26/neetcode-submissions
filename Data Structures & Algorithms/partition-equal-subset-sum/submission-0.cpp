class Solution {
public:
    bool canPartition(vector<int>& nums) {
          int total_sum = 0;
    
    // Calculate total sum of array
    for (int num : nums) {
        total_sum += num;
    }
    
    // If sum is odd, we cannot partition into two equal subsets
    if (total_sum % 2 != 0) {
        return false;
    }
    int sum = total_sum/2;
    vector<bool> dp(sum+1,false);
    dp[0] = true;
     for (int num : nums) {
            for(int j= sum; j>=num;j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
    }
    return dp[sum];
    }
};

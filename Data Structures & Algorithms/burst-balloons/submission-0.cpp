class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
       vector<int> num(n+2,1);
        for(int i=0;i<n;i++){
            num[i+1] = nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        return dfs(num,1,n,dp);
    }
    int dfs(vector<int> num,int i,int j, vector<vector<int>> &dp){
        if(i>j)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        dp[i][j] = 0;
        for(int l=i;l<=j;l++){
            int coins = num[i-1]*num[l]*num[j+1];
            coins+= dfs(num,i,l-1,dp) + dfs(num,l+1,j,dp);
            dp[i][j] = max(dp[i][j],coins);
        }
        return dp[i][j];
    }
};

class Solution {
public:
    int dfs(int amount, vector<int>& coins,vector<vector<int>>& dp,int i,int sum) 
    {
          if (sum == amount) return 1;
          if(i>=coins.size()||sum> amount)
       return 0;
       
        if(dp[i][sum]!= -1)
        return dp[i][sum];
        int res = 0;
        res+=dfs(amount,coins,dp,i,sum+coins[i]);
        res+=dfs(amount,coins,dp,i+1,sum);
        dp[i][sum] = res;
        return res;
      
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return dfs(amount,coins,dp,0,0);
       
    }
};

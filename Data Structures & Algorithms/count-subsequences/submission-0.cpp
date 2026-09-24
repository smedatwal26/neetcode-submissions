class Solution {
public:
    int m,n;
    int dfs(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(i==m){
        return 1;
        }
        if(i>=m || j>=n){
        return 0;
        }
        if(dp[i][j] != -1)
        return dp[i][j];
        int res = 0;
        if(t[i] == s[j]){
         res += dfs(s,t,i+1,j+1,dp);   
        }
         res += dfs(s,t,i,j+1,dp);    
         dp[i][j] = res;
           return res;
    }
    int numDistinct(string s, string t) {
        m = t.size();
        n = s.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return dfs(s,t,0,0,dp);
            }
};

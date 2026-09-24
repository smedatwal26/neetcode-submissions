class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return dfs(s,p,m,n,0,0,dp);
    }
    bool dfs(string s,string p,int m, int n,int i,int j,vector<vector<int>> &dp){
        if(j==n)
        return i==m;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool match = i<m && (s[i] == p[j] || p[j] == '.');
        if(j + 1 < n && p[j+1] == '*') {
            dp[i][j] = dfs(s,p,m,n,i,j+2,dp) || (match && dfs(s,p,m,n,i+1,j,dp));
        } else{
            dp[i][j] = match && dfs(s,p,m,n,i+1,j+1,dp);
        }
        return dp[i][j];
    }
};

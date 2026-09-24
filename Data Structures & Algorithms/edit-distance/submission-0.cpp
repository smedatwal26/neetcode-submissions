class Solution {
public:
    int r,c;
    int dfs(string w1, string w2, int i,int j, vector<vector<int>> &dp) {
        if(i==r && j==c)
        return 0;
        if(i>=r){
            return c-j;
        }
        if(j>=c){
            return r-i;
        }
        if(dp[i][j] != -1)
        return dp[i][j];
        int res = 0;
        if(w1[i] != w2[j]){
            res = min(dfs(w1,w2,i+1,j+1,dp),dfs(w1,w2,i+1,j,dp)) + 1;
            res = min(res,dfs(w1,w2,i,j+1,dp)+1);
        } else{
            res = dfs(w1,w2,i+1,j+1,dp);
        }
        return dp[i][j] = res;

    }
    int minDistance(string w1, string w2) {
        r = w1.size();
        c = w2.size();
        vector<vector<int>> dp(r+1,(vector<int> (c+1,-1)));
        return dfs(w1,w2,0,0,dp);
    }
};

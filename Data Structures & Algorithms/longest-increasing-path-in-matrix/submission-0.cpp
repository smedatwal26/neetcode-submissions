class Solution {
public:
    int r,c;
    int h[4] = {1,0,-1,0};
    int v[4] = {0,1,0,-1};
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i, int j){
        if(i>=r || j>=c)
        return 0;
        if(dp[i][j] != -1){
        return dp[i][j];
        }
        int res = 1;
        for(int k=0;k<4;k++){
            int row = i+h[k];
            int col = j+v[k];
           // cout<<dp[i][j]<<" fsefd";
            if(row < r && col < c && row >= 0 && col >=0 && matrix[i][j] < matrix[row][col]){
               res = max(res,dfs(matrix,dp,row,col) + 1);
                  
            }
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         r = matrix.size();
         c = matrix[0].size();
         int res = 1;
        vector<vector<int>> dp(r,vector<int> (c,-1));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(dp[i][j]==-1){
                res = max(res,dfs(matrix,dp,i,j));
                }
            }
        }
        return res;
    }
};

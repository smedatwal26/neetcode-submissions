class Solution {
public:
     int hor[4] = {1,0,-1,0};
    int ver[4] = {0,1,0,-1};
    int row,col;
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c] != 1)
        return 0;
        grid[r][c] = 0;
        int count =0;
        for(int i=0;i<4;i++){
            count += dfs(grid,r+hor[i],c+ver[i]);
        }
        return count + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
         col = grid[0].size();
         int ans = 0;
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                     int area = dfs(grid,i,j);
                     ans = max(ans,area);
                }
            }
         }
         return ans;   
    }
};

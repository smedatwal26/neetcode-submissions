class Solution {
public:
    int hor[4] = {1,0,-1,0};
    int ver[4] = {0,1,0,-1};
    int row,col;
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c] != '1')
        return;
        grid[r][c] = '0';
        for(int i=0;i<4;i++){
            dfs(grid,r+hor[i],c+ver[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         row = grid.size();
         col = grid[0].size();
         int ans = 0;
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1'){
                     dfs(grid,i,j);
                     ans++;
                }
            }
         }
         return ans;    
    }
};

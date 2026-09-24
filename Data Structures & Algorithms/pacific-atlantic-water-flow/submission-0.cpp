class Solution {
public:
int row,col;

    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &ocean,
    int r,int c){
        ocean[r][c] = true;
         vector<int> dir = {-1, 0, 1, 0, -1}; 
          for (int d = 0; d < 4; d++) {
            int x = r + dir[d], y = c + dir[d + 1];
            if(x >= 0 && x<row && y>=0 && y<=col && grid[r][c] <= grid[x][y] && !ocean[x][y]){
                dfs(grid,ocean,x,y);
            }
          }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> res;
        row = h.size();
        col = h[0].size();
        vector<vector<bool>> atl(row, vector<bool>(col, false));
        vector<vector<bool>> pac(row, vector<bool>(col, false));
         for(int i=0;i<row;i++){
            dfs(h,pac,i,0);
            dfs(h,atl,i,col - 1);
         }
          for(int i=0;i<col;i++){
            dfs(h,pac,0,i);
            dfs(h,atl,row - 1,i);
         }
        for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                if(atl[i][j] && pac[i][j]){
                    res.push_back({i,j});
                }
        }
        }
        return res;
       
    }
};

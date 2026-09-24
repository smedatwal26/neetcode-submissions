class Solution {
public:
    int row,col;
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
         row = grid.size();
         col = grid[0].size();
         queue<pair<int,int>> q;
         for(int r = 0;r<row ; r++){
            for(int c=0;c<col;c++){
                if(grid[r][c] == 0)
                 q.push({r,c});
            }
         }
         vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
         while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ro = r + dir[i][0];
                int co = c + dir[i][1];
                if(ro<0 || co<0 || ro>=row || co >=col || grid[ro][co]!= INF) {
                    continue;
                }
                else{
                grid[ro][co] = grid[r][c] + 1;
                q.push({ro,co});
                }
            }
         }
    }
};

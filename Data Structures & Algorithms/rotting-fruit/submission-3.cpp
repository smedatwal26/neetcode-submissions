class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        int fresh = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 2)
                q.push({i,j});
                if(grid[i][j] == 1)
                fresh++;
            }
        }
        if(q.empty() && fresh == 0)
        return 0;
        int ans = 0;
        while(!q.empty() && fresh != 0){
            ans++;
            int sz = q.size();
            for(int i = 0; i<sz;i++){
                auto cur = q.front();
                q.pop();
                int r = cur[0];
                int c = cur[1];
                int h[4] = {1,0,-1,0};
                int v[4] = {0,1,0,-1};
                for(int k = 0; k<4;k++)
                {
                    int row = r + h[k];
                    int col = c + v[k];
                    if(row < 0 || row >= n || col < 0 || col >=m || grid[row][col] != 1){
                        continue;
                    } else{
                    grid[row][col] = 2;
                    fresh--;
                    q.push({row,col});
                    }
                }
            }
        }
        if(fresh == 0)
        return ans;
        return -1;
    }
};

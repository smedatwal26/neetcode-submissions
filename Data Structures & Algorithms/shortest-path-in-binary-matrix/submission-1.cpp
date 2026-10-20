class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m1 = grid[0].size();
        int n1 = grid.size();
        queue<vector<int>> q;
        if(grid[0][0] != 0 || grid[n1 - 1][m1 - 1] != 0)
            return -1;
        if(n1 == 1 && m1 == 1)
            return 1;
        q.push({0,0});
        grid[0][0] = 1;
        int ans = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k < sz; k++){
                auto cur = q.front();
                q.pop();
                int n = cur[0], m = cur[1];
                int h[8] = {1,1,0,-1,-1,-1,0,1};
                int v[8] = {0,1,1,1,0,-1,-1,-1};
                for(int i = 0; i<8;i++){
                    int r = n + h[i];
                    int c = m + v[i];
                    if(r<0 || r >= n1 || c<0 || c>=m1 || grid[r][c] != 0){
                        continue;
                    } else{
                        if(r == n1-1 && c == m1 -1){
                            return ans+1;
                        }
                        grid[r][c] = 1;
                        q.push({r,c});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
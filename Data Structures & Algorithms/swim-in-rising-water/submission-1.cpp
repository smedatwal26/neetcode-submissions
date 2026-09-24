class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({grid[0][0],0,0});
        int h[4] = {1,0,-1,0};
        int v[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int t = cur[0], x = cur[1], y = cur[2];
            if(vis[x][y]) continue;
            vis[x][y] = true;
            if( x == n-1 && y == n-1)
            return t;
            for(int i=0;i<4;i++){
                int r = x + h[i];
                int c = y + v[i];
                if(r>=0 && r< n && c>= 0 && c<n && !vis[r][c]){
                    pq.push({max(t,grid[r][c]),r,c});
                }
            }
        }
        return -1;
    }
};

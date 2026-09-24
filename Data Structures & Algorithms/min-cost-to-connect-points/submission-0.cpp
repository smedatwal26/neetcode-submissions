class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        int res = 0;
        int edges = 0, node = 0;
        while(edges < n - 1){
            int u = -1;
            visited[node] = true;

            for(int i=0;i<n;i++){
                if(visited[i]) continue;
                int cur = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                minDist[i] = min(minDist[i],cur);
                if(u==-1 || minDist[i] < minDist[u]){
                    u = i;
                }
            }
            res += minDist[u];
            node = u;
            edges++;
        }
        return res;
        
    }
};

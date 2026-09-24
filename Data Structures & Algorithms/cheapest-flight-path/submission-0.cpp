class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        queue<tuple<int,int,int>> q;
        q.push({0,src,0});
        while(!q.empty()){
            auto [cst,node,stops] = q.front();
            q.pop();
            if(stops > k)
            continue;
            for(auto nei : adj[node]){
                int ne = nei.first, w = nei.second;
                int nextCost = cst + w;
                if(nextCost < prices[ne]){
                    prices[ne] = nextCost;
                    q.push({nextCost,ne,stops+1});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

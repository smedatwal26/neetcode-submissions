class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       
        int n = edges.size();
         vector<vector<int>> adj(n+1);
       
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
             vector<bool> vis(n+1,false);
             if(dfs(u,-1,adj,vis)){
                return {u,v};
             }
            
        }
        return {};
    }
    bool dfs(int u,int parent, vector<vector<int>> &adj,vector<bool> &vis){
        if(vis[u])
        return true;
        vis[u]= true;
        for(int n : adj[u]){
            if(n==parent) continue;
            if(dfs(n,u,adj,vis))
            return true;
        }
        return false;
    }
};

class Solution {
public:
    void dfs(vector<vector<int>> adj,int node,vector<bool> &vis){
        if(vis[node])
        return;
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(adj,i,vis);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
            int ans = 0;
            vector<bool> vis(n,false);
            vector<vector<int>> adj(n);
            for(auto ed : edges){
                adj[ed[0]].push_back(ed[1]);
                adj[ed[1]].push_back(ed[0]);
            }
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    ans++;
                    dfs(adj,i,vis);
                }
            }
            return ans;
    }
};

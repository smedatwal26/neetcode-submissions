class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1)
        return false;
        unordered_set<int> vis;
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!dfs(0,-1,adj,vis)){
            return false;
        }
        return vis.size() == n;
    }
    bool dfs(int n,int parent,vector<vector<int>> adj,unordered_set<int> &vis){
        if(vis.count(n)){
            return false;
        }
        vis.insert(n);
        for(auto node: adj[n]){
            if(node == parent)
            continue;
            if(!dfs(node,n,adj,vis))
            return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(const auto &ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto &[src, destinations] : adj) {
    sort(destinations.rbegin(), destinations.rend());  // now OK
}
        vector<string> route;
        dfs("JFK", adj, route);
        reverse(route.begin(),route.end());
        return route;
        
    }
    private:
        void dfs(const string &src, unordered_map<string,vector<string>> &adj, vector<string> &route){
            auto &dest = adj[src];
            while(!dest.empty()){
                string next = dest.back();
                dest.pop_back();
                dfs(next, adj, route);
            }
            route.push_back(src);
        }
};

class Solution {
public:
    vector<vector<pair<int,int>>> g; // g[u] = {(v, price)}
    vector<vector<int>> memo;
    const int INF = 1e9;
    int dst;

    int dfs(int u, int stepsLeft) {
        if (u == dst) return 0;
        if (stepsLeft == 0) return INF;

        int &res = memo[u][stepsLeft];
        if (res != -1) return res;

        res = INF;
        for (auto [v, w] : g[u]) {
            int sub = dfs(v, stepsLeft - 1);
            if (sub != INF) res = min(res, w + sub);
        }
        return res;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst_, int K) {
        dst = dst_;
        g.assign(n, {});
        for (auto &f : flights) {
            g[f[0]].push_back({f[1], f[2]});
        }

        // stepsLeft ranges 0..K+1 (edges allowed)
        memo.assign(n, vector<int>(K + 2, -1));

        int ans = dfs(src, K + 1);
        return (ans >= INF) ? -1 : ans;
    }
};

class UnionFind {

public:
    vector<int> par, rank;
    UnionFind(int n){
        par.resize(n);
        rank.assign(n,0);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }
    int find(int v){
        if(v != par[v]){
            par[v] = find(par[v]);
        }
        return par[v];
    }
    bool unionSets(int v1, int v2){
       int p1 = find(v1), p2 = find(v2);
       if(p1 == p2) return false;
       if(rank[p1] > rank[p2]){
        par[p2] = p1;
       }
       else if(rank[p1] < rank[p2]){
        par[p1] = p2;
       } else{
        par[p1] = p2;
        rank[p2]++; 
       }
       return true;
    }
};
class Solution {
public:
    int N;
    int Kruskals(vector<vector<int>> &vec, int skip, int add){
        int sum = 0;
        UnionFind uf(N);
        if(add != -1){
            uf.unionSets(vec[add][0],vec[add][1]);
            sum+= vec[add][2];
        }
        for(int i=0; i< vec.size() ; i++){
            if(i == skip)
            continue;
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];
            int x = uf.find(u);
            int y = uf.find(v);
            if(x!=y)
            {
                uf.unionSets(x,y);
                sum+=w;
            }
        }
        for(int i=0; i< N ; i++){
            if(uf.find(i) != uf.find(0))
            return INT_MAX;
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i=0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        int mstWeight = Kruskals(edges, -1, -1);
        vector<int> critical, pseudo;
       for(int i=0; i < edges.size(); i++){
            if(Kruskals(edges, i, -1) > mstWeight){
                critical.push_back(edges[i][3]);
            } else if(Kruskals(edges, -1, i) == mstWeight){
                pseudo.push_back(edges[i][3]);
            }
        }
        return {critical,pseudo};
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for(const auto &time : times){
            edges[time[0]].push_back({time[1],time[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});
        set<int> visited;
        int t = 0;
        while(!minHeap.empty()){
            auto cur = minHeap.top();
            minHeap.pop();
            int w1 = cur.first, n1 = cur.second;
            if (visited.count(n1)){
                continue;
            }
            visited.insert(n1);
            t = max(t,w1);
            for(const auto &next: edges[n1]){
                int n2 = next.first, w2 = next.second;
                if(!visited.count(n2)){
                    minHeap.push({w2 + w1, n2});
                }
            }
        }
        return visited.size() == n ? t: -1;

    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(int i=0;i<p.size();i++){
            int d = abs(p[i][0]*p[i][0]) + abs(p[i][1]*p[i][1]);
            pq.push({d,p[i]});
            if(pq.size() > k){
                    pq.pop();
            }
        }
        vector<vector<int>> res;
        for(int i = 0;i<k;i++){
            res.push_back({pq.top().second[0],pq.top().second[1]});
            pq.pop();
        }
        return res;
    }
};

class Solution {
public:
    int squarr(int x, int y){
        return ((x*x) + (y*y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> p;
        for(int i=0;i<points.size();i++){
            int dis = squarr(points[i][0],points[i][1]);
            if(p.size() >= k ){
                if(dis < p.top().first){
                    p.pop();
                    p.push({dis,points[i]});
                }
            } else{
                    p.push({dis,points[i]});
            }
        }
        vector<vector<int>> ans;
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> sortedQueries;
        for(int i =0; i<queries.size();i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(),sortedQueries.end());
        vector<int> res(queries.size(), -1);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minHeap;
        int i = 0;
        for(auto [q,idx] : sortedQueries){
            while(i<intervals.size() && q >= intervals[i][0]){
                int start = intervals[i][0], end = intervals[i][1];
                if(end >= q)
                minHeap.push({end-start+1,end});
                i++;
            }
            while(!minHeap.empty() && minHeap.top().second < q){
                minHeap.pop();
            }
            if(!minHeap.empty()){
                res[idx] = minHeap.top().first;
            }
        }
        return res;
    }
};

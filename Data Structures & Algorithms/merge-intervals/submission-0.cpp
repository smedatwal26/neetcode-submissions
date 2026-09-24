class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int last = ans.back()[1];
            if(start <= last){
                ans.back()[1] = max(end,last);
            } else {
                ans.push_back({start,end});
            }
        }
        return ans;

    }
};

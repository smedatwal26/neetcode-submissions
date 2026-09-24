/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start,end;
        for(auto &interval : intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int res = 0, count = 0 ,s = 0 , e = 0;
        while(s<start.size()){
            if(start[s] < end[e]){
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            res = max(count,res);
        }
        return res;

    }
};

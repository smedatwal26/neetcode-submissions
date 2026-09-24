class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        vector<int> count(26,0);
        for(int i=0;i<t.size();i++){
            count[t[i] - 'A']++;
        }
        int time =0;
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto i : count){
            if(i>0)
            pq.push(i);
        }
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()) {
                int cnt =  pq.top() - 1;
                pq.pop();
                if(cnt > 0){
                    q.push({cnt,time + n});
                }
            }else{
                time = q.front().second;
            }

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

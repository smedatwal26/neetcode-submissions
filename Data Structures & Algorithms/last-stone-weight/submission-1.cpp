class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max heap
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int ins = abs(x-y);
            if(ins != 0){
                pq.push(ins);
            }
        }
        return pq.size() == 0 ? 0 : pq.top();
    }
};

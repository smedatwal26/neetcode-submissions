class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a[cost.size() +1];
        a[0] = 0;
        a[1] = 0;
        for(int i=2; i<=cost.size();i++){
            a[i] = min(a[i-2]+cost[i-2],a[i-1] + cost[i-1]);
        }
        return a[cost.size()];
    }
};

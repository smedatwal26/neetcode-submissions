class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];
        int ans = 0;
        for(int i = 1; i< prices.size(); i++){
            m = min(m,prices[i]);
            ans = max(ans,prices[i] - m);
        }
        return ans;
    }
};

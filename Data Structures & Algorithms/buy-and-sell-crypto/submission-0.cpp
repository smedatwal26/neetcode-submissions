class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        int m = p[0];
        for(int i=0;i<p.size();i++){
            ans = max(p[i] - m,ans);
            m = min(p[i],m);
        }
        return ans;
    }
};

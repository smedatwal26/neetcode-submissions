class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size() - 1;
        int ans=0;
        while (l<r){
            int area = (r-l) * min(h[r],h[l]);
            ans = max(area,ans);
            if(h[r] > h[l]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};

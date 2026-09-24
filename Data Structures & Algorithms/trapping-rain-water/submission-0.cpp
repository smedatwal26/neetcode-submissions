class Solution {
public:
    int trap(vector<int>& h) {
       vector<int> pre(h.size(), 0);  // Initialize with the size of h and default values
    vector<int> post(h.size(), 0); 
        int m =0;
        for(int i=0;i< h.size();i++ ){
            pre[i] = max(h[i],m);
            m=pre[i];
        }
    //     m = 0;
    //     for (int i = h.size() - 1; i >= 0; i--) {
    //     m = max(h[i], m);
    //     post[i] = m;
    // }
    // int ans = 0;
    // for (int i = 0; i < h.size(); i++) {
    //     ans += min(pre[i], post[i]) - h[i];
    // }

    // return ans;
         m= 0;
        for(int i = h.size() -1;i>=0;i--){
            m = max(h[i],m);
            post[i] = m;
        }
        int ans = 0;
        for(int i=0;i< h.size();i++){
            ans+=min(pre[i],post[i]) - h[i];
        }
        return ans;
    }
};

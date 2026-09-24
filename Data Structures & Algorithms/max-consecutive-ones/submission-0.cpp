class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& n) {
        int ans = 0,s=0;
        for(int i = 0; i<n.size(); i++){
            if(n[i] == 1){
                s++;
                ans = max(ans,s);
            } else {
                s = 0;
            }
        }
        return ans;
    }
};
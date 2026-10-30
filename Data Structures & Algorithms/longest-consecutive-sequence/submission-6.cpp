class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int ans = 0;
        int cur = 0;

        for(int i : mp){
            if(mp.find(i - 1) == mp.end()){
                cur = 1;
                while(mp.find(i+1) != mp.end()){
                    cur++;
                    i = i+1;
                }
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};
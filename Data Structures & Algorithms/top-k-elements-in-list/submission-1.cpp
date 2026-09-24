class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
         vector<vector<int>> freq(nums.size() + 1);
        for (int n : nums) {
            m[n]++;
        }
        unordered_map<int, int>::iterator itr;
            for (itr = m.begin(); itr != m.end(); itr++) {
                freq[itr->second].push_back(itr->first);
            }
        vector<int> ans;
       for(int i= freq.size()-1;i>0;i--){
        for(int n:freq[i]){
            ans.push_back(n);
            if(ans.size() == k)
            return ans;
        }
       }
        return ans;
    }
};

class Solution {
public:
    void back(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> &cur){
            if(i==nums.size()){
                ans.push_back(cur);
                return;
            }
            back(nums,i+1,ans,cur);
            cur.push_back(nums[i]);
            back(nums,i+1,ans,cur);
            cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        back(nums,0,ans,cur);
        return ans;
    }
};

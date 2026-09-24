class Solution {
public:
    void back(vector<int>& nums, int target,set<vector<int>>& ans,vector<int> temp,
    int sum,int i,int n)
    {
        if(sum == target){
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
        }
        if(sum > target)
        return;
        if(i==n){
            return;
        }
        back(nums,target,ans,temp,sum,i+1,n);
        temp.push_back(nums[i]);
        sum+=nums[i];
        back(nums,target,ans,temp,sum,i + 1,n);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        back(candidates,target,ans,temp,0,0,candidates.size());
        vector<vector<int>> res;
        for(auto i : ans){
            res.push_back(i);
        }
        return res;
    }
};

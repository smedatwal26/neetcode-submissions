class Solution {
public:
    void back(vector<int>& nums, int target,vector<vector<int>>& ans,vector<int> temp,
    int sum,int i,int n)
    {
        if(sum == target){
        ans.push_back(temp);
        return;
        }
        if(sum > target)
        return;
        if(i==n){
            return;
        }
        temp.push_back(nums[i]);
        sum+=nums[i];
        back(nums,target,ans,temp,sum,i,n);
        temp.pop_back();
        sum -= nums[i];
        back(nums,target,ans,temp,sum,i + 1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        back(nums,target,ans,temp,0,0,nums.size());
        return ans;
    }
};

class Solution {
public:
    void back(vector<int>& arr,int i, int n, vector<vector<int>>& res,vector<int> temp){
        if(i==n){
        res.push_back(temp);
        return;
        }
        back(arr,i+1,n,res,temp);
        temp.push_back(arr[i]);
         back(arr,i+1,n,res,temp);
         return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        back(nums,0,nums.size(),ans,temp);
        return ans;
    }
};

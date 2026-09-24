class Solution {
public:
      void back(vector<int>& arr,int i, int n, set<vector<int>>& res,vector<int> temp){
        if(i==n){
        sort(temp.begin(),temp.end());
        res.insert(temp);
        return;
        }
        back(arr,i+1,n,res,temp);
        temp.push_back(arr[i]);
        back(arr,i+1,n,res,temp);
         return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        back(nums,0,nums.size(),ans,temp);
        vector<vector<int>> res;
        for(auto i : ans){
            res.push_back(i);
        }
        return res;
    }
};

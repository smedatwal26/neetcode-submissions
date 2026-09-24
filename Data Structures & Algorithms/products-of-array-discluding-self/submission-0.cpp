class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> le;
        int l=1,r=1;
        for(int i=0;i<nums.size();i++){
            le.push_back({l});
            l= l*nums[i];
        }
        //   for(int i=0;i<nums.size();i++){
        //     cout<<le[i]<<" ";
        //   }
        vector<int> ri;
          for(int i=nums.size()-1;i>=0;i--){
            ri.push_back({r});
            r= r*nums[i];
        }
        // cout<<endl;
        //   for(int i=0;i<nums.size();i++){
        //     cout<<ri[i]<<" ";
        //   }
       //   cout<<endl;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
        ans.push_back(le[i]*ri[nums.size()-i-1]);
        }
        return ans;
    }
};

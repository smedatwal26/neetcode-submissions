class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       int cost[n];
       cost[0] = nums[0];
       if(n>1){
        cost[1] = max(nums[1],nums[0]);
         for(int i=2 ;i<n;i++){
           cost[i] = max(cost[i-1],cost[i-2] + nums[i]);       
         }
    }
        return cost[n-1];
       } 
   
};

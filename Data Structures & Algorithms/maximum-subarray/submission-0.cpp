class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum = nums[0], cur = 0;
       for(int n : nums){
        if(cur<0){
            cur = 0;
        }
        cur+= n;
        maxSum = max(maxSum,cur);
       }
       return maxSum;
    }
};

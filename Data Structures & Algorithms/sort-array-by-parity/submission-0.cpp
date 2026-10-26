class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = nums.size() - 1; 
        int i = 0;
        while(i<j){
            bool odd = nums[i] % 2 == 0 ? false : true;
            bool even = nums[j] % 2 == 0 ? true : false;
            if(odd && even)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            } else if(!odd){
                i++;
            } else if(!even){
                j--;
            }
        }
        return nums;
    }
};
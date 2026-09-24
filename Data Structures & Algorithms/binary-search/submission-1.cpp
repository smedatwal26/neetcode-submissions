class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int n = nums.size();
        return binary(nums,i,n,target,n); 
    }
    int binary(vector<int>& nums,int i, int j, int target,int n){
        if(j >= i){
        int mid = i + (j - i) / 2;
        if(nums[mid] == target)
        return mid;
        if(nums[mid] > target){
        return binary(nums,i,mid -1 ,target,n);
        } else{
           return binary(nums,mid+ 1,j,target,n);
        }
        

        }
        return -1;
    } 
};

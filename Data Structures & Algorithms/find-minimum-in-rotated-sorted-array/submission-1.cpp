class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int low = 0,high = nums.size() -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            ans = min(ans,nums[mid]);
            if(nums[mid] < nums[low]){
                high = mid -1;
                if(mid > 0 && nums[mid] < nums[mid - 1] && ans < nums[mid])
                return nums[mid];
            }else{
                 // cout<<ans<<endl;
              //    cout<<mid<<endl;
                low = mid + 1;
                 if(mid <  nums.size() - 1 && nums[mid] > nums[mid +1] && ans < nums[mid])
                 return nums[mid + 1];
            }
        }
        return ans;
    }
};

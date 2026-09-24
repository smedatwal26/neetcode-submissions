class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> output(nums.size() - k + 1);
        deque<int> q;
        int r=0,l=0;
        while(r<nums.size()){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(l > q.front()){
                q.pop_front();
            }
            if(r+1 >= k){
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return output;
    }
};

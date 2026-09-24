class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end())
            s.insert(nums[i]);
        }
        if(nums.size() == 0)
        return 0;
        int len = 1,ans = 1;
        int prev = *s.begin();
       for (const int &value : s) {
       //  cout<< value<< endl;
         if(value == prev){
            continue;
         } else if(value - 1 == prev){
            ++len;
            // if(value == 6)
          //   cout<< "value: " << value << "len:" << len << endl;
            // cout<< len<< endl;
            ans = max(ans,len);
            prev = value;
         }
         else{
            len = 1;
            prev = value;
         }
       }
       return ans;
    }
};

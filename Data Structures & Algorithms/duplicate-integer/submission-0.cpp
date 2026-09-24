class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i : nums){
            if(st.find(i) != st.end()){
                return true;
            }
            else {
                st.insert(i);
            }
        }
        return false;
    }
};

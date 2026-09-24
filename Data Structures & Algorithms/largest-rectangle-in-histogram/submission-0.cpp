class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
        int n = h.size();
        stack<pair<int,int>> st;
        for(int i=0;i<h.size();i++){
            int start = i;
            while(!st.empty() && st.top().second > h[i]){
                int ind = st.top().first;
                int he = st.top().second;
                ans = max(ans,he*(i - ind));
                start = ind;
                st.pop();
            }
            st.push({start,h[i]});
        }
        while(!st.empty()){
            int ind = st.top().first;
            int he = st.top().second;
            ans = max(ans,he*(n - ind));
            st.pop();
        }
        return ans;
    }
};

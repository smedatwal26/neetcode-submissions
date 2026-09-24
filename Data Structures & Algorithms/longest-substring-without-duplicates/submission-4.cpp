class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0;
        if(s.size() == 0)
        return 0;
        int ans =1;
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = i;
            }
            else{
                j = max(m[s[i]] + 1,j);
                 m[s[i]] = i;
            }
            ans = max(i + 1 - j,ans);
            cout<< s[i]<< " "<< ans << endl;
        }
        return ans;
    }
};

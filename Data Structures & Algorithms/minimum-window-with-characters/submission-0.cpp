class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int count = t.size();
         int l = 0;
         string ans = "";
         int si = s.size() + 1;
        for(int r=0;r<s.size();r++){
            if(mp.find(s[r]) != mp.end()){
                mp[s[r]]--;
                if(mp[s[r]] >= 0){
                    count--;
                }
            }
                while(count == 0){
               //     cout<<l<<" "<<r<<endl;
                    if(si > r-l + 1){
                        ans = s.substr(l,r-l+1);
                        si = ans.size();
                    }
                   
                    if(mp.find(s[l])!=mp.end()){
                        mp[s[l]]++;
                        if(mp[s[l]] > 0)
                        {
                            count++;
                        }
                    }
                     l++;
                }

        }
        return ans;
    }
};

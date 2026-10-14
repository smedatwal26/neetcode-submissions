class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<26;i++){
            mp[i] = 0;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i] - 'a']++;
        }
        for(int i=0;i<s.size();i++){
            mp[t[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(mp[i] != 0)
            return false;
        }
        return true;

    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq;
        for(int i=0;i<s1.size();i++){
            freq[s1[i]]++;
        }
        int r=0;
        for(int l=0;l<s2.size();l++){
            unordered_map<char,int> temp = freq;
             bool ans = false;
            if(freq.find(s2[l]) != freq.end()){
                r = l;
               ans = true;
                while(r - l  < s1.size()){
                    if(r >= s2.size()){
                            ans = false; 
                            break;
                        }
                    if(temp.find(s2[r]) != temp.end()){
                        temp[s2[r]]--;
                        if(temp[s2[r]] < 0){
                            ans = false;
                            break;
                        }
                        r++;
                } else{
                    l = r;
                    ans = false;
                    break;
                }
                }
            }
            if(ans)
            return ans;
        }
        return false;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string alpha = "";
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&& s[i]<='z') ||(s[i]>='A'&& s[i]<='Z') ||(s[i]>='0'&& s[i]<='9'))
            alpha+=s[i];
        }
        int j=alpha.size()-1;
        for(int i=0;i<=j;i++){
            cout<<alpha[i]<<alpha[j];
            if(alpha[i] != alpha[j])
            return false;
            j--;
        }
        return true;
    }
};

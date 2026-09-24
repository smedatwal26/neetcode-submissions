class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.size();
        if (n == 0) return "";
        if(n==1) return s;
        int resLen = 0, idx = 0;
          vector<vector<bool>> dp(n, vector<bool>(n, false));
          for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i <=2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if(resLen < (j - i + 1)){
                        resLen = j - i + 1;
                        idx = i;
                    }
                }
            }
          }
          return s.substr(idx,resLen);
    }
};

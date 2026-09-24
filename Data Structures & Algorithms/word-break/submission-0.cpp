class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i=s.size() - 1 ; i>=0 ; i--){
            for(string word : wordDict){
                if(i + word.size() <= n 
                && word == s.substr(i,word.size())){
                    dp[i] = dp[i+word.size()];
                }
                if(dp[i])
                {
                    break;
                }
            }
        }
        return dp[0]; 
    }
};

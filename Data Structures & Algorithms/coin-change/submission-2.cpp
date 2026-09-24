class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res[amount + 1];
        sort(coins.begin(),coins.end());
        res[0] = 0;
        for(int i = 1; i<= amount ; i++){
            res[i] = amount + 1;
        }
        for(int i = 1; i<= amount ; i++){
           cout<<res[i-1]<<" ";
            for(int j : coins){
                if(j<=i)
              res[i] = min(res[i-j]+1,res[i]);
            }
        }
        return res[amount] == (amount + 1) ? -1 : res[amount];
    }
};

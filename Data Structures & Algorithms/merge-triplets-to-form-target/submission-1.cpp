class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& tar) {
       bool a = false, b = false, c = false;
       for(auto t : triplets) {
        if(t[0] > tar[0] || t[1] > tar[1] || t[2] > tar[2] ){
            continue;
        }
         if(t[0] == tar[0])
            a = true;
         if(t[1] == tar[1])
            b = true;
         if(t[2] == tar[2])
          c = true;
       }
       return a && b && c;
    }
};

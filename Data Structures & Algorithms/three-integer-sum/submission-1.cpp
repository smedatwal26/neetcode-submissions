class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int i=-1,j=a.size() -1 , k =i+1;
        while(i<j){
            i++;
            k= i+1;
            j= a.size() -1;
            while(k<j){
                if(a[i] + a[j] + a[k] == 0){
              
                    vector<int> s;
                    s.push_back(a[i]);
                    s.push_back(a[j]);
                    s.push_back(a[k]);
                    auto it = std::find(ans.begin(), ans.end(), s);

                  if (it == ans.end()) {
                    ans.push_back(s);
                  }
                          k++;
                }
                else if(a[i] + a[j] + a[k] > 0){
                    j--;
                }
                else{
                    k++;
                }
            }
            
        }
        return ans;
    }
};

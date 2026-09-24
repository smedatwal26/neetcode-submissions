class Solution {
public:
        unordered_map<int,vector<int>> mp;
        unordered_set<int> s;
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
      
        for(int i=0;i<numCourses;i++){
          mp[i] = {};
        } 
         
          for(auto& i : pr){
             mp[i[0]].push_back(i[1]);
          }
          for(int i=0;i<numCourses;i++){
            if(!dfs(i)){
                return false;
            }
          }
          return true;
    }
    bool dfs(int c){
        if(s.count(c)){
            return false;
        }
        if(mp[c].empty())
        {
            return true;
        }
        s.insert(c);
        for(int pre : mp[c]){
            if(!dfs(pre)){
                return false;
            }
        }
        s.erase(c);
        mp[c].clear();
        return true;
    }
};

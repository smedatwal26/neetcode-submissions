class Solution {
public:
         map<char,unordered_set<char>> adj;
         unordered_map<char, int> vis;
    string foreignDictionary(vector<string>& words) {
       for(auto word: words){
        for(char c: word){
            vis[c] = 0;
        }
       }
       for(int i=0; i<words.size() - 1 ; i++){
        string w1 = words[i];
        string w2 = words[i+1];
        int min_len = min(w1.size(),w2.size());
        bool diff = false;
        for(int j=0;j<min_len;j++){
            if(w1[j]!=w2[j])
            {
                adj[w1[j]].insert(w2[j]);
                diff = true;
                break;
            }
        }
            if(w1.size()>w2.size() && !diff)
            return "";
        }
        string res;
        for(auto c: vis){
            if(c.second == 0){
                if(!dfs(c.first,res)){
                    return "";
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
       }
       bool dfs(char c,string &result){
        vis[c] = 1;
        for(char node: adj[c]){
            if(vis[node] == 1)
            {
                return false;
            }
            if(vis[node] == 0)
            {
                if(!dfs(node,result)){
                    return false;
                }
            }
        }
        vis[c] = 2;
        result+=c;
        return true;
       }
};

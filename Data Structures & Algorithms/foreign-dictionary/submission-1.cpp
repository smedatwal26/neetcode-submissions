class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_set<char> chars;
        for(const string w: words){
            for(char c : w)
            chars.insert(c);
        }
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char, int> indeg;
        for(char c : chars) indeg[c] = 0;

        for(int i=0; i<words.size() - 1; i++){
            string &a = words[i];
            string &b = words[i+1];
        // invalid case is where abc , ab 
           if(a.size() > b.size() && a.compare(0, b.size(), b) == 0 ) 
           return "";
           int len = min(a.size() , b.size());
           for(int k=0 ; k<len; k++){
            if(a[k] != b[k]){
                if(adj[a[k]].insert(b[k]).second){
                    indeg[b[k]]++;
                }
                break;
            }
           }
        }
        queue<char> q;
        for(auto &p : indeg){
            if(p.second == 0)
            q.push(p.first);
        }
        string order;
        while(!q.empty()){
            char u = q.front();
            q.pop();
            order.push_back(u);
            for( char v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0)
                q.push(v);
            }
        }
        if(order.size() != chars.size()) return "";
        return order;
    }
};

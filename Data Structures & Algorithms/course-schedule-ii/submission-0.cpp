class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto p:prerequisites){
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        queue<int> q;
        vector<int> ans(numCourses);
        int count = 0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v = q.front();
            ans[numCourses - count - 1] = v;
            q.pop();
            count++;
            for(auto i : adj[v]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(numCourses==count)
        {
            return ans;
        }
        return {};
    }
};

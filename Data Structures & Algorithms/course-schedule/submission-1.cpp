class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto p : pre){
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for(int i; i< numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            count++;
            for(int node:adj[ind]){
                indegree[node]--;
                if(indegree[node] == 0){
                    q.push(node);
                }
            }
        }
        return count==numCourses;
    }
};

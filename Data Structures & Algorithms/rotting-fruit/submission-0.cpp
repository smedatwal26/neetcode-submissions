class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time = 0;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
       vector<vector<int>> dir= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(fresh>0 && !q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                   int row = r + dir[j][0];
                    int col = c + dir[j][1];
                    if(row<0 || col<0 || row>=grid.size() || col >= grid[0].size()
                    || grid[row][col] != 1){
                        continue;
                    }
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                }
            }
             time++;
        }
        return fresh==0 ? time : -1;

    }
};

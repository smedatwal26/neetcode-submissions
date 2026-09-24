class Solution {
public:
    int h[4] = {1,0,-1,0};
    int v[4] = {0,1,0,-1};
    int n;
    int m;
    bool dfs(vector<vector<char>>& board, string word,
    int r, int c,int k, vector<vector<bool>> visited){
        if(k==word.size())
        return true;
        if(r<0 || r>=n || c<0 || c>=m || board[r][c] != word[k] || visited[r][c]){
            return false;
        }
        visited[r][c] = true;
        for(int i=0;i<4;i++){
                if(dfs(board,word,r+h[i],c + v[i],k+1,visited)){
                    return true;
                }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Initializes an n x m matrix with 0s
         for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (dfs(board, word, r, c, 0,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

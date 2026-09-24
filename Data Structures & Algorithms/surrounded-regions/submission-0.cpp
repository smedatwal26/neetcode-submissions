class Solution {
public:
    int row,col;
    void capture(vector<vector<char>>& board, int r, int c){
        int h[4] = {1,0,-1,0};
        int v[4] = {0,1,0,-1};
        board[r][c] = '#';
        for(int i=0;i<4;i++){
            int ro = r + h[i];
            int co = c + v[i];
            if(ro > 0 && ro< row && co > 0 && co < col && board[ro][co] == 'O'){
                capture(board,ro,co);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
     //   bool vis[row][col] = {false};
     for(int r=0;r<row;r++){
        if(board[r][0] == 'O')
        capture(board,r,0);
         if(board[r][col -1] == 'O')
         capture(board,r,col-1);
     }
     for(int c=0;c<col;c++){
        if(board[0][c] == 'O')
        capture(board,0,c);
        if(board[row - 1][c] == 'O')
         capture(board,row - 1,c);
     }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'O'){
                   board[i][j] = 'X';
                }
                  if(board[i][j] == '#'){
                   board[i][j] = 'O';
                }
            } 
        }
    }
};

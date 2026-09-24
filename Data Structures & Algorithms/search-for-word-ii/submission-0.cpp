class TrieNode {
public:
    TrieNode* child[26];
    string isEnd;
    TrieNode() {
        for(int i=0;i<26;i++){
           child[i] = nullptr;
        }
        isEnd = "";
    }
};
class Solution {
public:
     vector<string> res;
    TrieNode* root; 
    int row,col; 

     void addWord(string word){
          TrieNode* cur = root;
           for (char c : word) {
            int i = c - 'a';
            if (cur->child[i] == nullptr) {
                cur->child[i] = new TrieNode();
            }
            cur = cur->child[i];
        }
        cur->isEnd = word;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
     root = new TrieNode();
      for(string word : words){
        addWord(word);
      }
       row = board.size();
       col = board[0].size();
       
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                dfs(board,root,r,c);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board,TrieNode* node,int r,int c){
        
         if(r<0 || c<0 || r>=row || c>=col || board[r][c] == '#' || node->child[board[r][c] - 'a'] == nullptr){
            return;
         }
         int idx = board[r][c] - 'a';
        node = node->child[idx];
        if(!node->isEnd.empty()){
            res.push_back(node->isEnd);
            node->isEnd = "";
        }
        char ch =  board[r][c];
        board[r][c] = '#';
        int hor[4] = {1,0,-1,0};
        int ver[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
                dfs(board,node,r+hor[i],c+ver[i]);
            }
        board[r][c] = ch;
    }
};

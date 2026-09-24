class Solution {
public:
void backtracking(int openN, int closedN, int n, vector<string>& res, string& stack) {
   if(openN == closedN && openN == n){
    res.push_back(stack);
    return;
   }
   if(openN < n){
    stack += '(';
    backtracking(openN + 1 , closedN , n, res, stack);
    stack.pop_back();
   }
   if(closedN < openN){
    stack += ')';
    backtracking(openN , closedN + 1, n, res, stack);
    stack.pop_back();
   }

}
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open =0 , close = 0;
        string stack;
        backtracking(0,0,n,res,stack);
        return res;
    }
};

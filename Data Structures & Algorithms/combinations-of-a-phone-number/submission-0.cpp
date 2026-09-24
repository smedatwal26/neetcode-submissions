class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return res;
         backtrack(0, "", digits);
          return res;
    }
     void backtrack(int i, string curStr, string &digits) {
        if(curStr.size() == digits.size()){
            res.push_back(curStr);
            return;
        }
        string str = digitToChar[digits[i] - '0'];
        for(char c: str){
            backtrack(i+1,curStr + c,digits);
        }
     }
};

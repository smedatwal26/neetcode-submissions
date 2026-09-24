class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        queue<pair<string,int>> q;
        for(string s:wordList){
            wordSet.insert(s);
        }
        if(wordSet.find(endWord)==wordSet.end())
        return 0;
        q.push({beginWord,1});
        while(!q.empty()){
            int step = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word==endWord)
            return step;
            for (int i = 0; i < word.size(); i++) {
                  char og = word[i];
                for(char j='a';j<='z';j++){
                 word[i] = j;
                 if(wordSet.find(word)!=wordSet.end()){
                    q.push({word,step+1});
                    wordSet.erase(word);
                 }
            }
            word[i] = og;
            }
        }
        return 0;
    }
};

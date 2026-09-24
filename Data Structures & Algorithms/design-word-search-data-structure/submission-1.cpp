class TrieNode {
public: 
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
        isEnd = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur =root;
        for(char c: word){
            if(c != '.'){
            int i = c - 'a';
            if(cur->child[i] == nullptr)
            cur->child[i] = new TrieNode();
            cur = cur->child[i];
            }
        }
        cur->isEnd = true;
    }
    bool searchsub(string word,TrieNode* cur,int ind){
        if(ind==word.size() &&  cur->isEnd)
        return true;
        // if(ind==word.size() - 1 &&  !cur->isEnd ){
        //     return false;
        // }
        for(int k = ind;k<word.size();k++){
            char c = word[k];
            if(c != '.'){
            int i = c - 'a';
            if(cur->child[i] == nullptr)
             return false;
            cur = cur->child[i];
            }else{
                 for(int j=0;j<26;j++){
                    
                    if(cur->child[j] != nullptr){
                        cout<< j<<endl;
                         TrieNode* temp = cur->child[j];
                   if(searchsub(word,temp,k+1)){
                    return true; 
                   }
                    }
                 }
                 return false;
            }
        }
        return cur->isEnd; 
    }
    bool search(string word) {
         TrieNode* cur =root;
         return searchsub(word,cur,0);
    }
};

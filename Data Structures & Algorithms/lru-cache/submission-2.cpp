class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int val,int key){
        this->val = val;
        this->key = key;
    }
};
class LRUCache {
public:
// (oldest)l -> nodes -> r(lastest)
    Node *left;
    Node *right;
    int cap;
    unordered_map<int,Node*> cache;
    void insert(Node* cur){
        Node* lat = right->prev;
        lat->next = cur;
        cur->prev = lat;
        cur->next = right;
        right->prev = cur;
    }
    void remove(Node* cur){
        Node* nex = cur->next;
        Node* prev = cur->prev;
        prev->next = nex;
        nex->prev = prev;
    }
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
        Node* cur = cache[key];
        remove(cur);
        insert(cur);
        return cur->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node *cur = new Node(value,key);
        cache[key] = cur;
        insert(cur);
        if(cap < cache.size()){
            Node* rem = left->next;
            remove(rem);
            cache.erase(rem->key);
            delete rem;
        } 
    }
};

class Node {
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int k,int v){
        val = v;
        key = k;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> cache;
    int cap;
    Node* left; // lru
    Node* right;// insert
    void insert(Node* node){
        Node *prev = right->prev;
        node->next = right;
        prev->next = node;
        right->prev = node;
        node->prev = prev;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
    LRUCache(int capacity) {
        cap =capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left-> next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    //insert
    //if already there we have to replace
    //if it exceeds cap then delete
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
           remove(cache[key]);
        }
        Node* node = new Node(key,value);
        cache[key] = node;
        insert(node);
        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

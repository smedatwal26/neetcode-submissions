class Node{
    public:
        string val;
        Node* next;
        Node* prev;
    public:
        Node(string value){
            val = value;
            next = NULL;
            prev = NULL;
        }
};
class BrowserHistory {
public:
    Node* head;
    Node* cur;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        cur = head;
    }
    
    void visit(string url) {
        Node* vis = new Node(url);
        cur->next = vis;
        vis->prev = cur;
        cur = vis;
    }
    
    string back(int steps) {
        while(steps>0 && cur->prev != NULL){
            cur = cur->prev;
            steps--;
        }
        return cur->val;
    }
    
    string forward(int steps) {
        while(steps>0 && cur->next != NULL){
            cur = cur->next;
            steps--;
        }
        return cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
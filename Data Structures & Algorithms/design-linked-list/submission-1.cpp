class MyLinkedList {
private:
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int value) {
            val = value;
            prev = nullptr;
            next = nullptr;
        }
    };

public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
       head = NULL;
       tail = NULL;
       size = 0;
    }
    
    int get(int index) {
        if(size<0 || size<=index)
        return -1;
        Node* cur = head;
        for(int i=0;i<index;i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(size ==0){
            head = newNode;
            tail = newNode;
         
        } else{
        
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        }
        size ++;
        return;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(size ==0){
            head = newNode;
            tail = newNode;
        } else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;        
        }
        size++;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(size<index || index<0)
        return;
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node* cur = head;
         for(int i=0;i<index;i++)
        {
            cur = cur->next;
        }
        Node *n = new Node(val);
        n->prev = cur->prev;
        n->next = cur;
        cur->prev = n;
        n->prev->next = n;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || size <= index){
            return;
        }
        Node *cur = head;
        for(int i=0; i<index;i++){
            cur = cur -> next;
        }
        if(cur->prev != NULL){
            cur->prev->next = cur->next;
        } else{
            head = cur->next;
        }
        if(cur->next != NULL){
            cur->next->prev = cur->prev;
        } else{
            tail = cur->prev;
        }
        delete cur;
        size--;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
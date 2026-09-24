/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldToNew;
        return dfs(node,oldToNew);
    }
    Node* dfs(Node* node,map<Node*,Node*> &oldToNew){
        if(node == nullptr)
        return nullptr;
        if(oldToNew.count(node)){
            return oldToNew[node];
        }
        Node* cur = new Node(node->val);
        oldToNew[node] = cur;
        for(int i=0;i<node->neighbors.size();i++){
            cur->neighbors.push_back(dfs(node->neighbors[i],oldToNew));
        }
        return cur; 
    }
};

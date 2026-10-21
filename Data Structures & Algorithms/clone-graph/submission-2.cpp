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
    Node* dfs(Node* node, unordered_map<Node*,Node*>& old){
        if(!node)
        return NULL;
        if(old.find(node)!=old.end())
        return old[node];

        Node* copy = new Node(node->val);
        old[node] = copy;
        for(Node* nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei,old));
        }
        return copy;

    }
    Node* cloneGraph(Node* node) {
        // Node *cur = new Node(node->val);
        unordered_map<Node*,Node*> oldToNew;
       // oldToNew[node] = new Node(node->val);
        return dfs(node,oldToNew);
    }
};

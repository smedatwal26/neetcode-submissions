/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int> mp;
        int h = 0;
        queue<TreeNode*> q;
        if(!root)
        return ans;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> level;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                mp[h] = node->val;
                level.push_back(node);
            }
        for(int i=0; i<level.size(); i++){
            TreeNode* node = level[i];
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        h++;
        }
        for(int i=0;i<h;i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};

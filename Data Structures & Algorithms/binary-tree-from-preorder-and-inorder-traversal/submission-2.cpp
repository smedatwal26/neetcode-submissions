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
    int idx = 0;
    
    TreeNode* dfs(vector<int>& pre, int l, int r, unordered_map<int,int> &mp){
        if(l>r)
        return NULL;
        int val = pre[idx++];
        int mid = mp[val];
        TreeNode* root = new TreeNode(val);
        root->left = dfs(pre, l, mid-1, mp);
        root->right = dfs(pre, mid + 1, r, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        idx = 0;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return dfs(preorder,0,inorder.size() - 1,mp);

    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,int> um;

    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(um.find(root)!=um.end())
            return (um.find(root)->second);
        int val=0;
        if(root->left!=NULL)
            val+=rob(root->left->left) + rob(root->left->right);
        if(root->right!=NULL)
            val+=rob(root->right->left) + rob(root->right->right);
        int temp=max(val+root->val, rob(root->left)+rob(root->right));
        
        um[root]=temp;    
        return temp;
    }
};

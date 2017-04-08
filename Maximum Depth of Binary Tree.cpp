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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lefty=maxDepth(root->left);
        int righty=maxDepth(root->right);
        
        int maxi=0;
        if(lefty>righty)
            maxi=lefty;
        else
            maxi=righty;
        return (maxi+1);
    }
};
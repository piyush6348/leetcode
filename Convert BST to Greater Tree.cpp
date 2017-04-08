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
    void convertBST(TreeNode* root,int &parentSum)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            parentSum+=root->val;
            root->val=parentSum;
            return;
        }
        convertBST(root->right,parentSum);
        root->val+=parentSum;
        parentSum=root->val;
        convertBST(root->left,parentSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        int parentSum=0;
        convertBST(root,parentSum);
        return root;
    }
};
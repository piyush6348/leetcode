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

    long getMax(TreeNode* root)
    {
        if(root==NULL)
            return LONG_MIN;
        
        TreeNode* temp=root;
        
        while(temp->right!=NULL)
            temp=temp->right;
            
        return temp->val;
    }
    
    long getMin(TreeNode* root)
    {
        if(root==NULL)
            return LONG_MAX;
        
        TreeNode* temp=root;
        
        while(temp->left!=NULL)
            temp=temp->left;
            
        return temp->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        
        if(root->left==NULL && root->right==NULL)
            return true;
        return (isValidBST(root->left) && isValidBST(root->right) && (getMax(root->left) < root->val) && (getMin(root->right)>root->val));
    }
};

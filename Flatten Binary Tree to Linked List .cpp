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
    void linkedList(TreeNode* root)
    {
        if(root==NULL)
            return ;
            
        linkedList(root->left);
        linkedList(root->right);
        
        TreeNode* temp=root->left;
        
        if(temp!=NULL)
        {
            while(temp->right!=NULL)
            temp=temp->right;
        
        temp->left=NULL;
        temp->right=root->right;
        root->right=root->left;
        root->left=NULL;   
        }
    }
    void flatten(TreeNode* root) {
        TreeNode* temp=root;
        if(temp!=NULL)
        linkedList(temp);
    }
};

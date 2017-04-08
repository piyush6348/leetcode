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
int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return sum;
        
        if(root->left!=NULL)
        {
            if(root->left->left==NULL)
            {
                if(root->left->right==NULL)
                {
                 sum+=(root->left->val);   
                }
            }
        }
        //cout<<root->val<<"\n";
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};
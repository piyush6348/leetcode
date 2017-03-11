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
    int mini=32767;
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int leftH=minDepth(root->left);
        int rightH=minDepth(root->right);
        int temp=0;
        if(rightH<leftH)
            temp=rightH;
        else
            temp=leftH;
        if(leftH==0)
            return rightH+1;
        if(rightH==0)
            return leftH+1;
        return temp+1;
    }
};
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
    int numNodes(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return (numNodes(root->left)+numNodes(root->right)+1);
    }
    int kthSmallest(TreeNode* root, int k) {
        int pos=numNodes(root->left);
            if(pos==k-1)
                return root->val;
            if(pos<k)
                return kthSmallest(root->right,k-pos-1);
            else if(pos>=k)
                return kthSmallest(root->left,k);
    }
};

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
vector<TreeNode*> ans;
    void getAncestor(TreeNode* temp,vector<TreeNode*> vec,TreeNode* search)
    {
        if(temp==NULL)
         return ;
        if(temp->left == search || temp->right==search)
        {
            vec.push_back(temp);
            vec.push_back(search);
            ans=vec;
            return ;
        }
        vec.push_back(temp);
        getAncestor(temp->left,vec,search);
        getAncestor(temp->right,vec,search);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        
        if(root==p || root==q)
            return root;
        
        TreeNode* lefty=lowestCommonAncestor(root->left,p,q);
        TreeNode* righty=lowestCommonAncestor(root->right,p,q);
            
            if(lefty!=NULL && righty!=NULL)
                return root;
            else{
                if(lefty!=NULL)
                    return lefty;
                return righty;
            }
        //return root;
    }
};

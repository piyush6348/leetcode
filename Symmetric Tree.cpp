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
    bool isSame(TreeNode* a,TreeNode* b)
    {
        if(a==NULL && b==NULL)
            return true;
        if(a==NULL || b==NULL)
            return false;
        return((a->val == b->val) && isSame(a->left,b->right) && isSame(a->right,b->left));
    }
    bool isSymmetric(TreeNode* root) {
        /*
        TreeNode* temp=root;
        if(root!=NULL)
        return isSame(temp->left,temp->right);
        else
            return true;*/
            if(root==NULL)
                return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        stack<TreeNode*> stk;
        stk.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* tempy=stk.top();
            stk.pop();
            
            if(temp==NULL)
            {
                if(!q.empty())
                    q.push(NULL);
                else
                    return true;
                while(!stk.empty())
                    stk.pop();
            }
            else
            {
                if(temp->val!=tempy->val)
                    return false;
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    stk.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    stk.push(temp->right);
                }
            }
            
        }
    }
};
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> stk;
        
        while(1)
        {
            while(root)
            {
                stk.push(root);
                ans.push_back(root->val);
                root=root->left;
            }
            if(!stk.empty())
            {
                TreeNode* temp=stk.top();
                stk.pop();
                root=temp->right;
            }
            else
                break;
        }
        return ans;
    }
};

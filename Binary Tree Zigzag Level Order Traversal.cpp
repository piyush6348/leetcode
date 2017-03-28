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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        vector<int> vec;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        //vec.push_back(root->val);
        stack<int> stk;
        int ct=1;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
                if(ct %2==1)
                {
                 ans.push_back(vec);
                 vec.clear(); 
                }
                else
                {
                    for(int i=0;i<vec.size();i++)
                        stk.push(vec[i]);
                    vec.clear();
                    while(!stk.empty())
                    {
                        vec.push_back(stk.top());
                        stk.pop();
                    }
                    ans.push_back(vec);
                    vec.clear();
                }
                if(!q.empty())
                    q.push(NULL);
                ct+=1;
            }else
            {
                vec.push_back(temp->val);
                //stk.push(root->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};
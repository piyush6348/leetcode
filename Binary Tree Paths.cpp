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
    
    void getPaths(TreeNode* root,string temp,vector<string> &vec)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
        {
            //char ch=root->val+'0';
            string ch=to_string(root->val);
            temp=temp+ch;
            vec.push_back(temp);
            return;
        }
        //char ch=root->val+'0';
        string ch=to_string(root->val);
        temp=temp+ch+"->";
        getPaths(root->left,temp,vec);
        getPaths(root->right,temp,vec);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        getPaths( root,"",vec);
        
        return vec;
    }
};
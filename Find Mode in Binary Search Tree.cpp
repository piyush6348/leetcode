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
    vector<int> vec;
    void sorted(TreeNode* root)
    {
        if(root==NULL)
            return;
        sorted(root->left);
        vec.push_back(root->val);
        sorted(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        sorted(root);
        unordered_map<int,int> um;
        for(int i=0;i<vec.size();i++)
        {
            if(um.find(vec[i])==um.end())
                um[vec[i]]=1;
            else
            {
                unordered_map<int,int>:: iterator itr=um.find(vec[i]);
                itr->second=itr->second+1;
            }
        }
        unordered_map<int,int>:: iterator itr;
        int maxi=0;
        for(itr=um.begin();itr!=um.end();itr++)
        {
            if(itr->second>maxi)
                maxi=itr->second;
        }
        vector<int> ans;
        
        for(itr=um.begin();itr!=um.end();itr++)
        {
            if(itr->second==maxi)
                ans.push_back(itr->first);
        }
        return ans;
    }
};
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
    
    unordered_map<int,int> mp;
    
    int findSum(TreeNode* root)
    {
        if(root == NULL)
           return 0;
         
         int leftSum=findSum(root->left);
         int rightSum=findSum(root->right);
         int totalSum=leftSum+rightSum+root->val;
         
         auto itr=mp.find(totalSum);
         if(itr!=mp.end())
         {
             int x=itr->second;
             mp.erase(itr);
             mp[totalSum]=x+1;
         }
         else
            mp[totalSum]=1;
         cout<<totalSum<<"\n";  
        return totalSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        vector<int>ans;
        
        if(root==NULL)
            return ans;
        
        int sum=findSum(root);
        int maximum=INT_MIN;
        
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second> maximum)
                maximum=itr->second;
        }
        
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second== maximum)
                ans.push_back(itr->first);
        }
        
        return ans;
    }
};

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
    
    int findElem(vector<int>& inorder,int elem){
        int i=0;
        while(inorder[i]!=elem)
            i+=1;
        return i;
    }
    TreeNode* buildTree(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe){
        if(ps>pe)
            return NULL;
        if(ps==pe){
            TreeNode* temp=new TreeNode(postorder[ps]);
            return temp;
        }
        TreeNode* temp=new TreeNode(postorder[pe]);
        int ind=findElem(inorder,postorder[pe]);
        int ir=(ie-is+1)-(ind-is+1);
        temp->left=buildTree(inorder,is,ind-1,postorder,ps,pe-ir-1);
        temp->right=buildTree(inorder,ind+1,ie,postorder,pe-ir,pe-1);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sze=inorder.size();
        if(sze==0)
            return NULL;
        return buildTree(inorder,0,sze-1,postorder,0,sze-1);
    }
};

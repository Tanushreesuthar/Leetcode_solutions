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
 bool path(TreeNode* root, TreeNode* p , vector< TreeNode*>&temp)
  {
        if(root==NULL)return false;
        temp.push_back(root);
        if(root->val==p->val)
        return true;
        if(path(root->left , p,temp) || path(root->right , p , temp))
       return true;
        temp.pop_back();
        return false;
       
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1 , path2;
        path(root , p  , path1);
        path(root , q  , path2);
        int n=path1.size();
        int m=path2.size();
        int x=min(n,m);
        for(int i=0;i<n;i++)
        {
            cout<<path1[i]->val<<" ";
        }
         cout<<endl;
        for(int i=0;i<m;i++)
        {
            cout<<path2[i]->val<<" ";
        }
        TreeNode* final =NULL;
        for(int i=0;i<x;i++)
        {
            
                if(path1[i]->val==path2[i]->val)
                {
                    final= path1[i];
                }
            
        }
        return final;
    }
};
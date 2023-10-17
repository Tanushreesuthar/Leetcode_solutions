/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int height(TreeNode* root)
  {
      if(root==NULL)return 0;
         int lf=height(root->left);
         int r8=height(root->right);
         if(abs(lf-r8)>1)return -1;
         if(lf==-1||r8==-1)return -1;
         return 1+max(lf,r8);
  }
    bool isBalanced(TreeNode* root) {
         if(height(root)==-1)return false;
         return true;
    }
};
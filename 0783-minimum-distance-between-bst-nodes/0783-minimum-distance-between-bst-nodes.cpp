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
//time O(n)
//space O(h)
class Solution {
public:
    void inorder (TreeNode* root, int &res,int &pre){
        if(!root) return;
        inorder(root->left,res,pre);
        if(pre!=-1) res=min(root->val - pre,res);
        pre=root->val;
        inorder(root->right,res,pre);
        
    }
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        int res=INT_MAX;
        int pre=-1;
        inorder(root,res,pre);
        return res;
    }
};
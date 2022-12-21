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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* l, TreeNode* r) {
        if(l->val < root->val && r->val < root->val)
        return lowestCommonAncestor(root->left,l,r);
        if(l-> val > root->val && r->val > root->val)
            return lowestCommonAncestor(root->right,l,r);
        return root;
    }
};
class Solution {
public:
    bool traverse(TreeNode *l,TreeNode *r)
    {
    if(!l && !r) return true;
    if (!l || !r) return false;
    if(l->val != r->val) return false;
    return  traverse(l->right,r->left) && traverse(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root){
        if(!root) return true;
        return traverse(root->left,root->right);
    }
};
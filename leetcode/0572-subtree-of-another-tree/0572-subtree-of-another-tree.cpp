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
    bool dfs(TreeNode* root,TreeNode *sub){
        if(!root || !sub) return root==sub;
        return root->val == sub->val && dfs(root->left,sub->left) && dfs(root->right,sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root || !sub) return root==sub;
        int val=0;
        if(root->val == sub->val) val=dfs(root,sub);
        return val || isSubtree(root->right,sub) || isSubtree(root->left,sub);
    }
};


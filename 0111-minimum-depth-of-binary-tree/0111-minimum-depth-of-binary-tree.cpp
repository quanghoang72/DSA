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
    //time O(n)
    //space O(n)
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return helper(root,1);
    }
    int helper(TreeNode* root, int level){
        if(!root)
            return INT_MAX;
        if(!root->left && !root->right)
            return level;
        int res=min({helper(root->left,level+1),helper(root->right,level+1)});
        return res;
    }
};
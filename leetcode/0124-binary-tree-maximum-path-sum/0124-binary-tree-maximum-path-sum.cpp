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
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        //post-order to get sum of subtree
        //kadane algorithm
        int l=max(dfs(root->left),0);
        int r=max(dfs(root->right),0);
        int cur=root->val+l+r; //current sum of subtree
        res=max(res,cur);
        //return max value path with max value subtree (left/right) 
        return root->val + max(l,r);
    }
};
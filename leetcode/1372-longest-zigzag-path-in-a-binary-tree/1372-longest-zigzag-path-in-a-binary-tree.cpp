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
    //space O(h)
    int res = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, false); 
        return res;
    }
    
    int dfs(TreeNode* root, bool isLeft) {
        if (!root) return -1;
        
        int l = dfs(root->left, false);
        int r = dfs(root->right, true);
        res = max(res, max(l + 1, r + 1));
        
        return isLeft ? l + 1 : r + 1; 
    }
};
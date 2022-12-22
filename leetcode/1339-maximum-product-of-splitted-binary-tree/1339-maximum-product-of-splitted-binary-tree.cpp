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
    long long ans=0,sum=0;
    int maxProduct(TreeNode* root) {
        sum=dfs(root); // cal total sum first
        dfs(root); //dfs again in post-order to cal max subtree
        return ans % (int)(1e9+7);
    }
    //post-order traversal to get the current subtree
    //left->right->parent
    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long cursum=dfs(root->left) +dfs(root->right) + root->val;
        ans=max(ans,(sum-cursum)*cursum);
        return cursum;
    }
};
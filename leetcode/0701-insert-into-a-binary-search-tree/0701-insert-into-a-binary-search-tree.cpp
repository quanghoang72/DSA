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
    TreeNode* insertIntoBST(TreeNode* root, int tar) {
        if(!root){
            TreeNode *tmp= new TreeNode(tar);
            tmp->left=NULL;
            tmp->right=NULL;
            return tmp;
        }
        if(root->val < tar) root->right=insertIntoBST(root->right,tar);
        else root->left=insertIntoBST(root->left,tar);
        return root;
    }
};
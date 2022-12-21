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
    bool valid(TreeNode* root,TreeNode* &pre){
        if(root){
            if(!valid(root->left,pre)) return false;
            if(pre!=NULL && pre->val >= root->val) return false;
            pre=root;
            return valid(root->right,pre);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=NULL;
        return valid(root,pre);
    }
};
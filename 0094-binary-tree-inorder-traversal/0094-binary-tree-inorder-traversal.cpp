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
    
    //recursion
    //time O(n)
    //space O(n)
    //     void inorder(TreeNode* root,vector<int> &res){
    //         if(!root) return;
    //         inorder(root->left,res);
    //         res.push_back(root->val);
    //         inorder(root->right,res);
    //     }
    //     vector<int> inorderTraversal(TreeNode* root) {
    //         vector<int> res;
    //         inorder(root,res);
    //         return res;
    //     }
    
    //iteration
    //time O(n)
    //space O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode*> s;
        vector<int> res;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            auto node = s.top();
            s.pop();
            res.push_back(node->val);
            root=node->right;
        }
        return res;
    }
};
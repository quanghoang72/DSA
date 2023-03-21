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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     preorder(root,res);
    //     return res;
    // }
    // void preorder(TreeNode* root, vector<int> &res){
    //     if(!root) return;
    //     res.push_back(root->val);
    //     preorder(root->left,res);
    //     preorder(root->right,res);
    // }
    
    //iteration
    //time O(n)
    //space O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            v.push_back(node->val);
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return v;
    }
};
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
    // time O(n)
    // space O(n)
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     postorder(root,res);
    //     return res;
    // }
    // void postorder(TreeNode* root, vector<int> &res){
    //     if(!root) return;
    //     postorder(root->left,res);
    //     postorder(root->right,res);
    //     res.push_back(root->val);
    // }

    //time O(n)
    //space O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<bool> visited;
        vector<int> res;
        s.push(root);
        visited.push_back(false);
        while(!s.empty()){
            auto node=s.top();
            s.pop();
            auto v=visited.back();
            visited.pop_back();
            if(node){
                if(!v){
                    s.push(node);
                    visited.push_back(true);
                    s.push(node->right);
                    visited.push_back(false);
                    s.push(node->left);
                    visited.push_back(false);
                }
                else{
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }

};
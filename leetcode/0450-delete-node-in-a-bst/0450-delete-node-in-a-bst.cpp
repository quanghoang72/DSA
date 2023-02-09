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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        //find and update subtree 
        if(key< root->val) 
            root->left=deleteNode(root->left,key);
        else if(key > root->val)
            root->right=deleteNode(root->right,key);
        
        else{
            //only 1 child
            if(!root->right) return root->left;
            if(!root->left) return root->right;
            
            //minimum node of right subtree
            auto cur=root->right;
            while(cur->left)
                cur=cur->left;
            root->val=cur->val;
            root->right=deleteNode(root->right,root->val); //continue delete that swap node in the right subtree
        }
        return root;
    }
};
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
    bool isLeaf(TreeNode *root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }   
//d=1-->left
//d=0-->right
int cal(TreeNode *root,int direct){
    if(!root) return 0;
    int res=0;
    if(isLeaf(root)&& direct==1)res+=root->val;
    else{
        res+=cal(root->left,1);
        res+=cal(root->right,0);
    }
    return res;
}

int sumOfLeftLeaves(TreeNode* root){
    int res=cal(root,2);
    return res;
}
};
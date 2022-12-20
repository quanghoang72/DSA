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
    // long sum=0;
    // void bfs(TreeNode* root,int l,int r){
    //     if(!root) return;
    //     if(root->val >= l && root->val <= r){
    //         sum+=root->val;
    //     }
    //     bfs(root->left,l,r);
    //     bfs(root->right,l,r);
    //     return;
    // }
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     if(!root) return 0;
    //     bfs(root,low,high);
    //     return sum;
    // }

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            int tmp=node->val;
            if(tmp>=low && tmp<=high) 
            {
                sum+=tmp;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            if(tmp > high){
                if(node->left) q.push(node->left);
            }
            if(tmp < low){
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }

};
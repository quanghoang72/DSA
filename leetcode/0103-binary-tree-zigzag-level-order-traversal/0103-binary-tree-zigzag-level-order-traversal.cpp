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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // if(!root) return {};
        // queue <TreeNode*> q;
        // q.push(root);
        // vector<vector<int>> res;
        // bool level=1;
        // while(!q.empty()){
        //     int sz=q.size();
        //     vector<int> tmp(sz);
        //     for(int i=0;i<sz;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         tmp[i]=node->val;
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     if(!level)
        //         reverse(tmp.begin(),tmp.end());
        //     res.push_back(tmp);
        //     level^=1;
        // }
        // return res;
        
        //deque
        if(!root) return {};
        deque<TreeNode*> d;
        d.push_back(root);
        bool ltr=1;
        vector<vector<int>> res;
        while(!d.empty()){
            int sz=d.size();
            vector<int> tmp(sz);
            for(int i=0;i<sz;i++){
                if(ltr){
                    auto x=d.back();
                    d.pop_back();
                    tmp[i]=x->val;
                    if(x->left)d.push_front(x->left);
                    if(x->right)d.push_front(x->right);
                }
                else{
                    auto x=d.front();
                    d.pop_front();
                    tmp[i]=x->val;
                    if(x->right)d.push_back(x->right);
                    if(x->left)d.push_back(x->left);
                }
            }
            res.push_back(tmp);
            ltr^=1;
        }
        return res;
    }
};
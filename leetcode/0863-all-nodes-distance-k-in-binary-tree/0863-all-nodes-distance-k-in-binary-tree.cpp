/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //time O(n)
    //space O(n)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto cur=q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                    mp[cur->val].push_back(cur->left->val);
                    mp[cur->left->val].push_back(cur->val);
                }
                if(cur->right){
                    q.push(cur->right);
                    mp[cur->val].push_back(cur->right->val);
                    mp[cur->right->val].push_back(cur->val);
                }
            }
        }
        vector<int> res;
        dfs(mp,res,target->val,k,target->val);
        return res;
    }
    void dfs(unordered_map<int,vector<int>> &mp,vector<int> &res,int cur,int k,int pre){
        if(k==0){
            res.push_back(cur);
            return;
        }
        for(auto nei: mp[cur]){
            if(nei!=pre){
                dfs(mp,res,nei,k-1,cur);
            }
        }
    }
};

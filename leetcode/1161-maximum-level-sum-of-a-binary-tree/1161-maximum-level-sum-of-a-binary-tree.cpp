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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int res=INT_MAX;
        long sum=root->val;
        int level=1;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            long temp=0;
            for(int i=0;i<sz;i++){
                auto cur=q.front();
                q.pop();
                temp+=cur->val;
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
            if(temp>sum){
                res=level;
                sum=max(sum,temp);
            }
            level++;
        }
        return res==INT_MAX ? 1: res;

    }
};


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
    // int sum(TreeNode* root,int t,long cur){
    //     if(!root) return 0;
    //     cur+=root->val;
    //     return (cur==t) + sum(root->left,t,cur) + sum(root->right,t,cur);
    // }
    // int pathSum(TreeNode* root, int targetSum) {
    //     if(!root) return 0;
    //     return sum(root,targetSum,0) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    // }
    unordered_map <long,int> mp;
    int ans=0;
    void cnt(TreeNode* root,int t,long sum){
        if(!root) return;
        sum+=root->val;
        if(sum==t) ans++;
        if(mp.find(sum-t)!=mp.end()){
            ans+=mp[sum-t];
        }
        mp[sum]++;
        cnt(root->left,t,sum);
        cnt(root->right,t,sum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root,int targetSum){
        cnt(root,targetSum,0);
        return ans;
    }
};
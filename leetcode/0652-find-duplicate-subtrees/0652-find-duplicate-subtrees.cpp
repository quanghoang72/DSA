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
    //time O(n^2)
    //space O(n^2)
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        if(!root) return {};
        unordered_map<string,int> mp;
        dfs(root,res,mp);
        return res;
    }
    string dfs(TreeNode* root,vector<TreeNode*> &res,unordered_map<string,int> &mp){
        if(!root) return "";
        string s= dfs(root->left,res,mp) + "," + dfs(root->right,res,mp) + "," + to_string(root->val);
        cout << s << endl;
        if(mp[s]==1) res.push_back(root);
        mp[s]++;
        return s;
    }
};
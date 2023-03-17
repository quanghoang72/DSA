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
    //time O(n)
    //space O(n)
    // preorder = parent -> left -> right. go from left to right, root is at the first node
    //inorder indicates the left and right children of an invidual node
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++) mp[in[i]]=i;
        int n=in.size();
        int idx=0;
        return helper(pre,in,idx,0,n-1);
    }
    TreeNode *helper(vector<int> &pre,vector<int> &in,int &idx,int start,int end){
        if(start > end) return nullptr;
        TreeNode* root=new TreeNode(pre[idx++]);
        int pos=mp[root->val];
        root->left=helper(pre,in,idx,start,pos-1);
        root->right=helper(pre,in,idx,pos+1,end);
        return root;
    }
};
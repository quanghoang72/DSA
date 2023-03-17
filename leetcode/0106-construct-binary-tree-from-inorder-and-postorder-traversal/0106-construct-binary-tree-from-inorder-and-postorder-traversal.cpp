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
    // postorder =  left -> right -> parent .root is at the last node, go from right to left (traverse backward of post array)
    //inorder indicates the left and right children of an invidual node
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < size(inorder); i++) mp[inorder[i]] = i;
        int n=inorder.size();
        int idx=n-1;
        return helper(inorder,postorder,0,n-1,idx);
    }
    TreeNode* helper(vector<int> &inorder,vector<int>&postorder,int start,int end,int &idx){
        if(start>end) return nullptr;
        TreeNode *node = new TreeNode(postorder[idx--]);
        int parent= mp[node->val]; 
        node->right=helper(inorder,postorder,parent+1,end,idx);
        node->left=helper(inorder,postorder,start,parent-1,idx);
        return node;
    }
};

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
    int widthOfBinaryTree(TreeNode* root) {
        int res=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            int start=q.front().second;
            int end=q.back().second;
            res=max(res,end-start+1);
            for(int i=0;i<sz;i++){
                auto [node,order]=q.front();
                q.pop();
                if(node->left)
                    q.push({node->left,(long long)order*2+1});
                if(node->right)
                    q.push({node->right,(long long)order*2+2});
            }
            level++;
        }
        return res;
    }
};
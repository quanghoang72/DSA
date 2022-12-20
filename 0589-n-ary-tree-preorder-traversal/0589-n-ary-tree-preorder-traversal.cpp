/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void treeToArr(Node* root,vector<int>&res){
        if(root){
            res.push_back(root->val);
            for(int i=0;i < root->children.size();i++){
                treeToArr(root->children[i],res);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        treeToArr(root,res);
        return res;
    }
};

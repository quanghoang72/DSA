/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp; 
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* head=new Node(node->val);//copy node
        mp[node]=head; //map old node ref to the new copy ref

        for(auto it:node->neighbors){
            if(mp.count(it)){ //found
                head->neighbors.push_back(mp[it]); //map new node to new copy ref node
            }
            else{
                head->neighbors.push_back(cloneGraph(it));
            }
        }
        return head;
    }
};
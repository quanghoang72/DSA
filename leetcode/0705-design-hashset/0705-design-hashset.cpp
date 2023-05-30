class Node {
public:
        int data;
        Node *nxt;
        Node(){
            data=0;
            nxt=NULL;
        }
        Node(int key){
            this->data=key;
            this->nxt=NULL;
        }
};
class MyHashSet {
public:
    int sz=10007;
    vector<Node*> s;
    MyHashSet() {
        s.resize(sz,new Node());
    }
    
    void add(int key) {
        auto cur = s[key%sz];
        while(cur->nxt){
            if(cur->nxt->data == key)
                return;
            cur=cur->nxt;
        }
        cur->nxt=new Node(key);
    }
    
    void remove(int key) {
        auto cur = s[key%sz];
        while(cur->nxt){
            if(cur->nxt->data == key){
                cur->nxt=cur->nxt->nxt;
                return;
            }
            cur=cur->nxt;
        }
    }
    
    bool contains(int key) {
        auto cur = s[key%sz];
        while(cur->nxt){
            if(cur->nxt->data == key)
                return 1;
            cur=cur->nxt;
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
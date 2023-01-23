class Node{
  public:
    int k;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int value)
    {
        k=key;
        val=value;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        left= new Node(0,0);
        right= new Node(0,0);
        left->next=right; //left for lru
        right->prev=left; //right for most use
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            //if already exist then remove node and update later
            remove(cache[key]);
            delete cache[key];
        }
        cache[key]=new Node(key,value);
        insert(cache[key]);

        if(cache.size() > cap){
            //remove the next node of left
            Node* lru=left->next;
            remove(lru);
            cache.erase(lru->k);
            delete lru;
        }
    }
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node *left;
    Node *right;
    //remove node
    void remove(Node *node){
        Node* pre=node->prev;
        Node* nxt=node->next;
        //skip current node
        pre->next=nxt;
        nxt->prev=pre;
    }
    //insert node to the right as recent use
    void insert(Node* node){
        Node *pre=right->prev;
        Node* nxt=right;
        //assign recent used node in between right node and previous node
        pre->next=node;
        node->prev=pre;

        node->next=nxt;
        nxt->prev=node;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
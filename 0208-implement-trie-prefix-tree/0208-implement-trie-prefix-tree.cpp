class Trie {
public:
    Trie() {
        
    }
    Trie *children[26]={};
    bool isEndWord=false;
    void insert(string word) {
        Trie* cur = this;
        for(char c: word){
            c= c - 'a';
            if(cur->children[c]==nullptr)
                cur->children[c]= new Trie();
            
            cur=cur->children[c];
        }
        cur->isEndWord=1;
    }
    
    bool search(string word) {
        Trie* cur=this;
        for(char c:word){
            c-='a';
            if(cur->children[c]==nullptr)
                return false;
            cur=cur->children[c];
        }
        return cur->isEndWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur=this;
        for(char c:prefix){
            c-='a';
            if(cur->children[c]==nullptr)
                return false;
            cur=cur->children[c];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
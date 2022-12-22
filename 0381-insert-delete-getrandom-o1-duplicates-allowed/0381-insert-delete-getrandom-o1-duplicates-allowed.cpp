class RandomizedCollection {
public:
    vector<int> v;
    //value , set of index
    unordered_map<int, unordered_set<int>> m;
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size()-1); //index
        return m[val].size()==1; //if unique or not
    }
    
    bool remove(int val) {
        auto it=m.find(val);
        if(it!=end(m)){
            //swap last element with removed value
            auto pos=*it->second.begin(); //first idx 
            it->second.erase(it->second.begin()); 
            v[pos]=v.back();
            m[v.back()].insert(pos);//insert new index
            m[v.back()].erase(v.size()-1); //earase old one
            v.pop_back();
            //if removed value is unique one -->remove that val in map
            //if not be erased, it can be find at the next remove 
            if(it->second.size()==0) m.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
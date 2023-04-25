class SmallestInfiniteSet {
public:
    int mn=1;
    vector<bool> v;
    SmallestInfiniteSet() {
        v=vector<bool>(1001,1);
    }

    int popSmallest() {
        int res=mn;
        v[mn++]=0;
        while(!v[mn]){
            mn++;
        }
        return res;
    }
    
    void addBack(int num) {
        if(v[num])
            return;
        v[num]=1;
        mn=min(mn,num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
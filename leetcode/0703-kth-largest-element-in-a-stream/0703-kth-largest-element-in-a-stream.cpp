class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> maxheap;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        for(auto val:nums){
            maxheap.push(val);
            while(maxheap.size()>k){
                maxheap.pop();
            }
        }
        sz=k;
    }
    
    int add(int val) {
        maxheap.push(val);
        while(maxheap.size()>sz){
                maxheap.pop();
        }
        return maxheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
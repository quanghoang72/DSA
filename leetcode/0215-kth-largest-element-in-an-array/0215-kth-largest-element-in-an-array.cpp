class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int n=a.size();
        // priority_queue <int> max_heap(a.begin(),a.end());
        // for(int i=0;i<k-1;i++){
        //     max_heap.pop();
        // }
        // return max_heap.top();
        priority_queue <int,vector<int>,greater<int>> min_heap;
        for(auto i:a){
            min_heap.push(i);
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        return min_heap.top();
        
    }
};
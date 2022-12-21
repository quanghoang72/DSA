class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n=a.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){map[a[i]]++;}
        vector<int> res;
        //min heap
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        // for(auto i : map){
        //     min_heap.push({i.second,i.first});
        //     if(min_heap.size()>k) min_heap.pop(); 
        //     //get rid of size-k smallest element = contain only largest k element
        // }
        // while(!min_heap.empty()){
        //     res.push_back(min_heap.top().second);
        //     min_heap.pop();
        // }
        // return res;
        
        //bucket sort
        vector<vector<int>> bucket(n+1);
        for(auto i:map){
            bucket[i.second].push_back(i.first);
            //assign element array into the frequence index
        }
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                res.push_back(bucket[i][j]);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
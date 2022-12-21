class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        //to store invidual string freq
        unordered_map<string, int> freq;
        
        for(auto w : words){
            freq[w]++;
        }
        
        //comparitor same as max_heap
        //in decrease order of freq
        //if same frequency then arrange by their lexicographical order
        auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        
        //allias a existing type data == user define                        //declare typpe
        typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > my_priority_queue_t;
        my_priority_queue_t  pq(comp);
        
        //iterate freq map to push to queue
        for(auto w : freq ){
            pq.emplace(w.first, w.second);
            
            //only contain k value
            if(pq.size()>k) pq.pop();
        }
        
        vector<string> output;
        while(!pq.empty()){
            cout << pq.top().first << endl;
            output.insert(output.begin(), pq.top().first);
            pq.pop();
        }
        return output;
    }
};
class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int start=*s.begin();
        int end=*s.begin();
        for(auto it= ++s.begin();it!=s.end();it++){
            int value=*it;
            if(value-end==1)
                end=value;
            else{
                intervals.push_back({start,end});
                start=end=value;
            }
        }
        intervals.push_back({start,end});
        return intervals;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
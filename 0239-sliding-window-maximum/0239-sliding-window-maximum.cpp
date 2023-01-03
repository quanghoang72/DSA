class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        //monotic queue = queue in decreasing order
        deque<int> d;
        int n=a.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            //the front queue is out of window se we remove it 
            while(!d.empty() && d.front() <= i-k)
                d.pop_front();
            while(!d.empty() && a[i]>a[d.back()])  //when meet a larger element
                d.pop_back();
            d.push_back(i); //push into the back to maintain the larget in the front
            if(i>=k-1){ //valid window k size
                res.push_back(a[d.front()]);
            }
        }
        return res;
    }
};
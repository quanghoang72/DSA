class BrowserHistory {
public:
    // int idx=0;
    // vector<string> v;
    // BrowserHistory(string homepage) {
    //     v.push_back(homepage);
    // }
    
    // void visit(string url) {
    //     v.resize(idx+1);
    //     v.push_back(url);
    //     idx++;

    // }
    
    // string back(int steps) {
    //     int preidx=max(0,idx-steps);
    //     idx=preidx;
    //     return v[idx];
    // }
    
    // string forward(int steps) {
    //     int nxtidx=min((int)v.size()-1,idx+steps);
    //     idx=nxtidx;
    //     return v[idx];
    // }

    stack <string> previous; //store current url
    stack <string> next;    //store next url when going backward

    BrowserHistory(string homepage) {
        previous.push(homepage);
        next = stack<string>(); //empty
    }
    
    void visit(string url) {
        previous.push(url);
        next = stack<string>(); //clear forward history url
    }
    
    string back(int steps) {
        while(steps && previous.size()>1){
            next.push(previous.top());
            previous.pop();
            steps--;
        }
        return previous.top();
    }
    
    string forward(int steps) {
        while(steps && next.size()>0){
            previous.push(next.top());
            next.pop();
            steps--;
        }
        return previous.top();
    }

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
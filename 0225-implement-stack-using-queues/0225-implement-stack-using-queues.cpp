class MyStack {
public:
    queue<int> cur;
    MyStack() {
        
    }
    
    void push(int x) {
        cur.push(x);
    }
    
    int pop() {
        int n=cur.size();
        int t;
        for(int i=0;i<n;i++){
            t=cur.front();
            cur.pop();
            if(i!=n-1)cur.push(t);
        }
        return t;
    }
    
    int top() {
        int n=cur.size();
        int t;
        for(int i=0;i<n;i++){
            t=cur.front();
            cur.pop();
            cur.push(t);
        }
        return t;
    }
    
    bool empty() {
        return cur.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
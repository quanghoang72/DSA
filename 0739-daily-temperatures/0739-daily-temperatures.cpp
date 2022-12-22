class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
    int n=t.size();
    vector<int> res(n,0);
    //in the rightmost element res will be 0 if there is no larger element
    stack<int>s;
    for(int i=0;i<n;i++){
        //every t[i] > stack top --> res can be assign
        //while loop is used to find if is there any tem that can lower to the "i boundary"
        while(!s.empty() && t[i] > t[s.top()]){
            res[s.top()]=i-s.top();
            s.pop();
        }
        //keep push to stack 
        s.push(i);
    }
    return res;
    
    // reverse iterator
    // int n = t.size();
    // vector<int> ans(n);
    // stack<int> st;
    // for (int i = n-1; i >= 0; i--)
    // {
    //     while (!st.empty() && t[i] >= t[st.top()])
    //         st.pop();
    //     if (st.empty())
    //         ans[i] = 0;
    //     else
    //         ans[i] = st.top()-i;
    //     st.push(i);
    // }
    // return ans;
    }
};
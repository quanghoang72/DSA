class Solution {
public:
    //time O(n)
    //space O(n)
    string simplifyPath(string s) {
        string res="/";
        int i=0;
        int n=s.size();
        stack<string> stk;
        bool containWords=0; //to remove last slash
        while(i<n){
            while(i<n && s[i]=='/') i++;

            string temp;
            while(i<n && s[i]!='/') temp+=s[i++];

            if(temp==".."){
                if(!stk.empty()) stk.pop();
            }
            else if(temp!="" && temp!=".")stk.push(temp);
        }
        
        if(!stk.empty())  containWords=1;

        stack<string> reverseStk;
        while(!stk.empty()){
            reverseStk.push(stk.top());
            stk.pop();
        }
        cout << endl;
        while(!reverseStk.empty()){
            res+=reverseStk.top() +"/";
            cout << res << endl;
            reverseStk.pop();
        }
        if(containWords)res.pop_back();
        return res;
    }
};

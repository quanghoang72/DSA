class Solution {
public:
    int evalRPN(vector<string>& a) {
        unordered_map<string,function<long long (long long,long long)>> mp={
            {"+", [](long long a,long long b) { return a+b; }},
            {"-", [](long long a,long long b) { return a-b; }},
            {"*", [](long long a,long long b) { return a*b; }},
            {"/", [](long long a,long long b) { return a/b; }}
        };
        stack<long long> stack;
        for (string s : a) {
            if (!mp.count(s)) {
                stack.push(stoi(s));
            } else {
                long long op1 = stack.top();
                stack.pop();
                long long op2 = stack.top();
                stack.pop();
                stack.push(mp[s](op2,op1));
            }
        }
        return stack.top();
    }
};
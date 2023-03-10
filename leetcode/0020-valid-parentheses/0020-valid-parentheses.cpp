class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c:s)
        {            
            switch(c)
            {
                case '(': stk.push(')');break;
                case '[': stk.push(']');break;
                case '{': stk.push('}');break;
                default:
                    if(stk.empty()|| stk.top()!=c) return false;
                    stk.pop();
            }    
        }
        return stk.empty();
    }
};
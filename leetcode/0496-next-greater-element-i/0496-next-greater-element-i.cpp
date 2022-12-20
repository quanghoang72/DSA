class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int i=0;i<b.size();i++) {
            //if there is element that greater than stack top
            //map stack top to next greater element
            while (s.size() && s.top() < b[i]) {
                m[s.top()] = b[i];
                s.pop();
            }
            s.push(b[i]);
        }
        vector<int> ans;
        for (int i : a) ans.push_back(m.count(i) ? m[i] : -1);
        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<vector<int>>&a) {
        map<int, int> count;
        vector<int> res;
        for (auto i : a) {
            for (auto j : i) {
                count[j]++;
                
                if (count[j] == a.size())
                     res.push_back(j);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
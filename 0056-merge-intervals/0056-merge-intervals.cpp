class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if(a.size()<=1) return a;
        sort(begin(a),end(a));
        vector<vector<int>> res;
        res.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            //previous end >= current start
            if(res.back()[1]>=a[i][0]) res.back()[1]= max(res.back()[1],a[i][1]);
            else res.push_back(a[i]);
        }
        return res;
    }
};
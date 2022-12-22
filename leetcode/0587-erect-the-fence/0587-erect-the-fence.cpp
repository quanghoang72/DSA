class Solution {
public:
        vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        // if 3 node listed in cw order -> orientation will be ccw --> pop last node
        // else 3 node listed in ccw order --> orientation will be cw (ac) --> push 
        // Andrew's monotone chain method
        int n = points.size();
        vector<vector<int>> ans;
            
            
        sort(points.begin(), points.end(), mycompare);
        //{1,1} {2,0} {2,2} {2,4} {3,3} {4,2}
        // left to right
        // try to find clockwise minimum x to maximum x
        for (int i = 0; i < n; ++i) {
            // remove back when 3 points is ccw
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
                ans.pop_back();
            ans.push_back(points[i]);
        }
    
        // if all points along a line, ans.size() is n after left to right procedure
        if (ans.size() == n) return ans;

        // right to left
        for (int i = n-2; i >= 0; --i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
                ans.pop_back();
            ans.push_back(points[i]);
        }
        //remove the last element because it's dup from the first index
        ans.pop_back();
        return ans;
    }
    //in ascending order of x
    static bool mycompare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0]);
    }
};
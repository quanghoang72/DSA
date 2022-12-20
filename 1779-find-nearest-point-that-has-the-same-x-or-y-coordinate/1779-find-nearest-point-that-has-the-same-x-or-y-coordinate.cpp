class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size(), mn = INT_MAX, ans = -1, diff;
        for(int i = 0; i < n; i++)
            if(points[i][0] == x || points[i][1] == y){
                diff = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(diff < mn)
                    mn = diff, ans = i;            
            }
        return ans;
    }
};
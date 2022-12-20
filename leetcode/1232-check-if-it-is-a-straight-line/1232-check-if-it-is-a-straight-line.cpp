class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int r=a.size();
        int diffx=a[1][0]-a[0][0];
        int diffy=a[1][1]-a[0][1];
        for(int i=2;i<r;i++){
            if(diffx*(a[i][1] - a[0][1]) != diffy*(a[i][0] - a[0][0])) return false;
        }
        return true;
    }
};
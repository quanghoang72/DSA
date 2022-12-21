class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int r=a.size();
        int c=a[0].size();
        int x=0,y=c-1;
        //search from right top corner
        while(x < r && y>=0){
            if(a[x][y]==target) return true;
            a[x][y]>target ? y-- : x++;
        }
        return false;
    }
};
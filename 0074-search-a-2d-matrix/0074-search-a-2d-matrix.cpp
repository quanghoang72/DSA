class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int r=a.size(),c=a[0].size();
        int l=0,h=r*c;
        while(l<h){
            int m=(l+h)/2;
            int x=m / c;
            int y=m % c;
            if(a[x][y]==target) return true;
            else if(a[x][y]>target) h=m;
            else l=m+1;
        }
        return false;
    }
};
class Solution {
public:
    //time O(m*n)
    //space O(1)
    
    //starting top left -> only go down and right to reach the bottom right
    //minimum value at any cell = min(a[i-1][j],a[i][j-1])
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        //cover 2 edges case where only 1 row or 1 colum
        //so the result(last cell a[n-1][m-1]) is acummulation
        
        //first row
        for(int i=1;i<m;i++){
            a[0][i]+=a[0][i-1];
        }
        
        // first column
        for(int i=1;i<n;i++){
            a[i][0]+=a[i-1][0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j]+=min(a[i-1][j],a[i][j-1]);
            }
        }
        return a[n-1][m-1];
    }

};
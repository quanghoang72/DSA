class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) {
        vector <int> row(a.size());
        vector <int> col(a[0].size());

        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                row[i]+=a[i][j]; //count 1s in row
                col[j]+=a[i][j]; // count 1s in col
            }
        }
        vector<vector<int>> res (a.size(), vector<int> (a[0].size()) );
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++) {
                res[i][j]=2*row[i]+2*col[j]-a.size()-a[i].size();
            }
        }
        return res;
    }
};
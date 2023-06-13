class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=0;
        unordered_map<string,int>  mp;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp+=to_string(grid[i][j]) + "-";
            }
            temp.pop_back();
            mp[temp]++;
        }
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp+=to_string(grid[j][i])+"-";
            }
            temp.pop_back();
            auto it=mp.find(temp);
            res+=it!=mp.end() ? it->second : 0;
        }
        return res;
    }
};
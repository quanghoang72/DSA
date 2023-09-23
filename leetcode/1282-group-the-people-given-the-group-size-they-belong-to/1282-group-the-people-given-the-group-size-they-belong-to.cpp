class Solution {
public:
    // time O(n)
    // space O(n)
    vector<vector<int>> groupThePeople(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> mp(n+1);
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            mp[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            vector<int> temp;
            for(int j=0;j<mp[i].size();j++){
                temp.push_back(mp[i][j]); 
                if(temp.size()==i){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};
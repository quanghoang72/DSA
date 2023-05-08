class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& a) {
        vector<vector<int>> res;
        int n=a.size();
        unordered_map<int,int>mp;
        int mx=0;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            mx=max(mx,mp[a[i]]);
        }
        for(int i=0;i<mx;i++){
            vector<int> temp;
            for(auto &x:mp){
                if(x.second>0){
                    temp.push_back(x.first);
                    x.second--;   
                }
            }
            res.push_back(temp);
        }
        return res;
        
    }
};
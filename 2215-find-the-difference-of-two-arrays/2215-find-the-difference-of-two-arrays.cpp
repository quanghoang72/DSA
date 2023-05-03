class Solution {
public:
    //time O(n)
    //space O(n)
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>mp;
        for(auto val : a){
            mp[val]=1;
        }
        
        for(auto val:b){
            if(mp[val]==0) mp[val]=2;
            else if(mp[val]==1 || mp[val]==-1)
                mp[val]=-1;
        }
        
        vector<vector<int>> res(2);
        
        for(auto i:mp){
            if(i.second==1)
                res[0].push_back(i.first);
            else if(i.second==2)
                res[1].push_back(i.first);
        }
        return res;
    }
};
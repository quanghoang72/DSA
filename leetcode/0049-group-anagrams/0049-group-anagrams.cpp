class Solution {
public:
    //time O(n*m)
    //space O(n*m)
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<a.size();i++){
            string temp=a[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(a[i]);
        }
        for(auto x : mp){
            res.push_back(x.second);
        }
        return res;
    }
};
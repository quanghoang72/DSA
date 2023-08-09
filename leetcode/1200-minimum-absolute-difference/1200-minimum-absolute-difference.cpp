class Solution {
public:
    //time O(nlogn)
    //space O(n^2)
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(),a.end());
        int smallestDiff=INT_MAX;
        unordered_map<int,vector<vector<int>>> mp;
        vector<vector<int>> res;
        for(int i=1;i<a.size();i++){
            int gap=a[i]-a[i-1];
            mp[gap].push_back({a[i-1],a[i]});
            smallestDiff=min(smallestDiff,gap);
        }
        for(auto v:mp[smallestDiff]){
            res.push_back(v);
        }
        return res;
    }
};

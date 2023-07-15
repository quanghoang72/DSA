class Solution {
public:
    //time O(n)
    //space O(n)
    int longestSubsequence(vector<int>& a, int diff) 
    {
        int res=1;
        unordered_map<int,int> mp;
        for(auto i : a){
            mp[i]=mp[i-diff]+1;
            res=max(res,mp[i]);
        }
        return res;
    }
};
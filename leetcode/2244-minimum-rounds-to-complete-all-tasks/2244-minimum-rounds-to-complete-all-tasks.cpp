class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto x : tasks)  mp[x]++;
        int res=0;
        for(auto x : mp){
            if(x.second <2) return -1;
            res+=(x.second+2)/3;
        }
        return res;
    }
};
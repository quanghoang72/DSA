class Solution {
public:
    int findJudge(int n, vector<vector<int>>& a) {
        vector<int> trust_count(n+1);
        for(auto &i : a){
            trust_count[i[0]]--;
            trust_count[i[1]]++; //increasing trust
        }
        for(int i=1;i<=n;i++){
            if(trust_count[i]==n-1) return i;
        }
        return -1;
    }
};
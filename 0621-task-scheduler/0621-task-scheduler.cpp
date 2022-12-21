class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        vector<int> cnt (26,0);
        int most=0;
        for(char c: a){
            cnt[c-'A']++;
            most=max(most,cnt[c-'A']);
        }
        // (max-1) cycle of most appear character
        int ans=(most-1)*(n+1);

        // find character has the same freq and add to ans
        // as a last cycle
        for(int i=0;i<26;i++){
            if(cnt[i]==most) ans++;
        }
        return max((int)a.size(),ans);
    }
};
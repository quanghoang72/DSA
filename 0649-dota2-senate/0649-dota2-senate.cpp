class Solution {
public:
    //time O(n)
    //space O(n)
    string predictPartyVictory(string a) {
        queue<int> r;
        queue<int> d;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]=='R'){
                r.push(i);
                continue;
            }
            d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int rIdx=r.front(); r.pop();
            int dIdx=d.front(); d.pop();
            if(rIdx < dIdx)
                r.push(rIdx+n);
            else
                d.push(dIdx+n);
        }
        return r.size() > d.size() ? "Radiant" : "Dire";
    }
};
class Solution {
public:
    //time O(n)
    //space O(n)
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n<2){
            return n;
        }
        unordered_set<int> s;
        int res=1,cur=1;
        for(auto x : a) s.insert(x);
        for(auto i : s){
            //if there is no left element(i-1) then i is a start element
            if(s.find(i-1)==s.end()){
                cur=1;
                //if next consecutive element appears
                while(s.find(i+cur)!=s.end()){
                    cur++;
                }
                res=max(res,cur);
            }
        }
        return res;
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushh, vector<int>& popp) {
        //time O(n)
        //space O(n)
        // stack<int> s;
        // for(int i=0,j=0;i<pushh.size();i++){
        //     s.push(pushh[i]);
        //     while(!s.empty() && s.top()==popp[j]){
        //         s.pop();
        //         j++;
        //     }
        // }
        // return s.empty();
        
        //time O(n)
        //space O(1)
        int i=0,j=0;
        int n=pushh.size();
        for(auto num : pushh){
            pushh[i++]=num;
            while(i>0 && pushh[i-1]==popp[j]){
                i--;
                j++;
            }
        }
        return i==0;
    }
};
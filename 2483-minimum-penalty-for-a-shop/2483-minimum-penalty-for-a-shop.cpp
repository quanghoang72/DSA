class Solution {
public:
    //time O(n)
    //space O(1)
    int bestClosingTime(string customers) {
        int n=customers.size();
        int res=INT_MAX;
        int penalty=INT_MAX;
        
        int cnt_N=0; 
        int cnt_Y=0;
        
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')
                cnt_Y++;
        }
        for(int i=0;i<=n;i++){
            int cur_pen=cnt_Y+cnt_N;
            if(penalty>cur_pen){
                penalty=cur_pen;
                res=i;
            }
            i < n && customers[i]=='Y' ? cnt_Y-- : cnt_N++;
        }
        return res;
    }
};
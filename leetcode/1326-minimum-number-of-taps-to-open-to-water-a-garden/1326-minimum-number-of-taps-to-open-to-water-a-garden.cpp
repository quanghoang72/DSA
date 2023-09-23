class Solution {
public:
    //time O(nlogn)
    //space O(n)
    int minTaps(int target, vector<int>& ranges) {
        int n=ranges.size();
        int res=1;
        vector<vector<int>> pipe;
        int mx_reach=0;
        for(int i=0;i<n;i++)
        {
            int start=max(0,i-ranges[i]);
            int end=min(target,i+ranges[i]);
            int sz=end-start;
            //eliminate size of cover area = 0
            if(sz==0) 
                continue;
            mx_reach=max(mx_reach,end);
            pipe.push_back({start,end,sz});
        }
        if(pipe.size()==0 || mx_reach <target)
            return -1;

        //sort starting value for consecutive intervals
        sort(pipe.begin(),pipe.end(),[&](vector<int>a,vector<int>b){
            return a[0]==b[0] ? a[2] > b[2] : a[0]<b[0];
        });

        int cur_s=pipe[0][0],cur_e=pipe[0][1];
        for(int i=0;i<pipe.size();i++){
            int best_option=-1; 
            int gap=target-cur_e; //distance from current ending point to target point
            int j=i;
            for(;j<pipe.size() && pipe[j][0]<=cur_e;j++){
                if(target-pipe[j][1] < gap){
                    
                    gap=target-pipe[j][1];
                    best_option=j;
                }
            }

            //gap between current interval to next starting point 
            if(best_option==-1 && cur_e<target)
                return -1;
            i=j-1;

            //there is an intervals to pick
            if(best_option!=-1){
                cur_e=pipe[best_option][1];
                res++;
            }
        }
        return res;

    }
};
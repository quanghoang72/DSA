class Solution {
public:
    //time O(nlogn)
    //space O(1)
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=INT_MAX;
        int res=INT_MAX;
        while(l<r){
            int m=l+(r-l)/2;
            double total=0;
            for(int i=0;i<dist.size();i++){
                double tempd=dist[i]*1.0/m;
                int tempi=ceil(tempd);
                total+= (tempi==tempd || i==dist.size()-1) ? tempd : tempi;
            }
            if(total <= hour){
                r=m;
                res=min(res,m);
            }
            else
                l=m+1;
        }
        return res==INT_MAX ? -1 : res;
    }
};
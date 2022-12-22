class Solution {
public:
    int subarrayLCM(vector<int>& a, int k) {
        int n=a.size();
        int curlcm;
        int count=0;
        for(int i=0;i<n;i++){
            curlcm=1;
            for(int j=i;j<n;j++){
                curlcm=lcm(curlcm,a[j]);
                if(curlcm==k) count++;
                if(curlcm>k) break;
            }
        }
        return count;
    }
};

class Solution {
public:
    //time O(n)
    //space O(1)
    vector<int> shuffle(vector<int>& a, int n) {
        // vector<int> res;
        // for(int i=0,j=n;i<n;i++,j++){
        //     res.push_back(a[i]);
        //     res.push_back(a[j]);
        // }
        // return res;
        
        for(int i=n;i<a.size();i++){
            a[i]=a[i]*1024+a[i-n];
        }
        for(int i=n,idx=0;i<a.size();i++,idx+=2){
            a[idx]=a[i]%1024;
            a[idx+1]=a[i]/1024;
        }
        return a;
    }
};

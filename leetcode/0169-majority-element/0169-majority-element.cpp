class Solution {
public:
    //moore voting algorithm
    // time O(n)
    // space O(1)
    int majorityElement(vector<int>& a) {
        
        int n=a.size();
        int idx=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[idx]){
                cnt++;
            }
            else cnt--;
            //change the major
            if(cnt<=0){
                cnt=1;
                idx=i;
            }
        }
        int freq=0;
        //check again the freq of that element
        for(int i=0;i<n;i++)
            if(a[i]==a[idx]) freq++;
        return freq> (n/2) ? a[idx] : -1;
    }
};
class Solution {
public:
    //time O(nlogn)
    //space O(1)
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        vector<int> v;
        int n=a.size();
        for(int i=0;i<n;i++){
            int val=a[i];
            if(v.empty() || v.back() <= val){
                v.push_back(val);
                a[i]=v.size();
            }
            else{
                int pos=upper_bound(v.begin(),v.end(),val)-v.begin();
                v[pos]=val;
                a[i]=pos+1;
            }
        }
        return a;
    }
};
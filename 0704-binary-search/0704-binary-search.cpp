class Solution {
public:
    int search(vector<int>& a, int t) {
        int n=a.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==t) return mid;
            else if(a[mid]<t) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        long high=n;
        while(low<=high){
            long mid=(low+high)/2;
            if(isBadVersion(low)) return low;
            else if(isBadVersion(mid)) high=mid;
            else low=mid+1;
        }
        return 1;
    }
};
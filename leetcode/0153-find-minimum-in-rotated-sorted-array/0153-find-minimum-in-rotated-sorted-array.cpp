class Solution {
public:
    //time O(logn)
    //space O(1)
    int findMin(vector<int>& a) {
        int n=a.size();
        int l=0;
        int h=n-1;
        while(l<h){
            //sorted order
            if(a[l]<a[h]) return a[l];

            int mid=(l+h)/2;

            //left partition of the rotated array is greater than right
            //then we will meet the end of the ascending order and reach the start(minimum) number
            //if we continue going to the right
            if(a[mid]>=a[l])
                l=mid+1;
            //mid < left it means any right side of mid value is always larger
            //it is better to go to the left to seek for smaller one
            else h=mid;

        }
        return a[l];
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> res(2);
        int n=a.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int sum=a[low]+a[high];
            if(sum==target) {
                res[0]=low+1;
                res[1]=high+1;
                break;
            }
            else if(sum<target) low++;
            else high--;
        }
        return res;
    }
};
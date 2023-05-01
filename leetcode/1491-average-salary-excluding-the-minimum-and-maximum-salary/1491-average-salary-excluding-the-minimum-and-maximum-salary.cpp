class Solution {
public:
    //time O(nlogn)
    //space O(1)
    double average(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int mx=a[n-1];
        int mn=a[0];
        int temp=0;
        for(auto salary : a){
            if(salary== mx || salary ==mn) continue;
            temp+=salary;
            cout << temp << endl;
        }
        return (double)temp/(n-2);
    }
};

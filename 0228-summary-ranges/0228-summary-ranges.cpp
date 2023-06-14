class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        vector<string> res;
        for(int i=0;i<a.size();i++){
            int j=i+1;
            while(j<a.size() && a[j]-1==a[j-1]){
                j++;
            }
            j--;
            string temp= j > i  ? to_string(a[i]) + "->" +  to_string(a[j]) : to_string(a[i]);
            res.push_back(temp);
            i=j;
        }
        return res;
    }
};
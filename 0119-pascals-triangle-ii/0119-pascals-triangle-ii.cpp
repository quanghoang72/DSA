class Solution {
public:
    vector<int> getRow(int idx) {
        //row C colum
        // row 5 col 3 = 5C3 = 10
        vector<int> res(idx+1,0);
        res[0]=res[idx]=1;
        int numerator=idx;
        int denominator=1;
        long temp=1;
        for(int i=1;i<idx;i++,numerator--,denominator++)
        {
            temp=temp * numerator/denominator;
            res[i]=temp;
        }
        return res;
    }
};
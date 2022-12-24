class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
    //to do this inplace O(1) space
    // set the first row to represent if there is a zero in that column
    // and first col for row except first cell because
    // the cell(0,0) will be overlap therefore use a variable to present first row
    // to avoid conflict
        
        bool first_zero_row=0; //to determine if there is a zero in firstrow or not
        int r=a.size();
        int c=a[0].size();
        //find where is 0
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==0){
                    //that column should contains all 0
                    a[0][j]=0;
                    //row should contains all 0
                    (i>0) ? a[i][0]=0 : first_zero_row=true;
                }
            }
        
        }
        //spread 0 according to first row and first col
        //except for the first col. if the [0][0]=0 then a[0][j] always true
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                //    row     ||     col
                if(a[i][0]==0 || a[0][j]==0)
                    a[i][j]=0;
            }
        }
        //check first cell to spread 0 in first col
        if(!a[0][0]){
            for(int i=1;i<r;i++){
                a[i][0]=0;
            }
        }
        //first row
        if(first_zero_row){
            for(int i=0;i<c;i++){
                 a[0][i]=0;
             }
        }
    }
};
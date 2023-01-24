class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& a) {
        int res=0;
        queue<int> q; 
        q.push(1);
        int n=a.size();
        int destination=n*n;
        while(!q.empty()){
            res++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front();q.pop();
                for(int j=1;j<=6;j++){ //all posible number of dice
                    int y=x+j; //position value in 1-d array    
                    if(y>destination) continue; //out of bound
                    
                    //convert value back to 2d array = matrix
                    int r=(y-1)/n;
                    int c=(y-1)%n;
                    
                    //if the row is even then normal index increasing from left to right
                    //otherwise, compute reverse index
                    int &v=a[n-1-r][(r%2==0)?c:n-1-c];//reference of that value in matrix

                    if(v==0) continue; //checked visited 
                    if(v>0){ //go through a snake/ladder (that value is always greater than -1)
                        y=v;
                    }
                    v=0; //visited
                    if(y==destination) return res; //check if we reach the destination
                    q.push(y); 
                }
            }
        }
        return -1;
    }
};
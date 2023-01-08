class Solution {
public:
    //time O(n*n)
    //space O(n)
    
    //same line = same slope
    //parallel to y -> slope = inf
    //parallel to x-> slope = 0
    int maxPoints(vector<vector<int>>& a) {
        int res=1;
        int n=a.size();
        for(int i=0;i<n;i++){
            //create every map for single points to avoid repeat points with same slope in later iteration
            unordered_map<double,int> mp;
            for(int j=i+1;j<n;j++){
                double dx=a[j][0]-a[i][0];
                double dy=a[j][1]-a[i][1];
                double slope;
                if(dx==0){ //perpendicular lines with x-axis 
                    slope=INT_MAX; //avoid -inf and inf
                }
                else{
                    slope=dy/dx;
                }
                mp[slope]++;
            }
            for(auto x : mp){
                //+1 for the point at a[i] its self
                res=max(res,x.second+1);
            }
        }
        return res;
    }
};
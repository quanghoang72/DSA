class Solution {
public:
    //time O(n)
    //space O(n)
    int leastBricks(vector<vector<int>>& a) {
        //map used to store the position at end of the brick
        //for each cut except for two edge of the wall, if the more bricks'edge at that pos
        //the less bricks suppose to be cut
        unordered_map<int,int>mp;
        int maxf=0; //most postiion appear
        int n=a.size();
        for(int i=0;i<n;i++){
            int length=0; //starting pos of every row
            for(int j=0;j<a[i].size()-1;j++){
                length+=a[i][j]; //consecutive length from each brick
                mp[length]++;
                maxf=max(maxf,mp[length]);
            }
        }
        return n-maxf;
    }
};
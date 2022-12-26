class Solution {
public:
    bool canJump(vector<int>& a) {
        //reachable is the maximum value that we can reach untill now
        int reachable=0;
        
        //iterator i used to traverse every step because if the element is not 0 than we can jump in min length = 1
        //if reachable less than i then at the current point we cant reach to i --> Break
        for(int i=0;i<=reachable;i++){
            reachable=max(reachable,i+a[i]);
            if(reachable>=a.size()-1) return true; //reach the last pos
        }
        return 0;
    }
};
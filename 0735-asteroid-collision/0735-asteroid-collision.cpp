class Solution {
public:
    //time O(n)
    //space O(n)
    
    //Compute the case when the asteroid on the left is positive and the right is negative
    //ADD the new one to stack when it is in the same direction with the previous one
    //or it is the biggest asteroid we have met
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> s;
        int n=asteroids.size();
        vector<int> res;
        bool get=1; //consider to put in stack or not
        for(int i=0;i<n;i++){
            while(!s.empty() && asteroids[s.top()] > 0 && asteroids[i] < 0){
                //newest asteroid get exploded 
                if(abs(asteroids[s.top()])>abs(asteroids[i])){
                    get=0;
                    break;
                }
                //every encountered asteroid exploded
                else if(abs(asteroids[s.top()])<abs(asteroids[i]))
                    s.pop();
                //previous and recent one both are destroyed
                else{
                    s.pop();
                    get=0;
                    break;
                }
                
            }
            if(get) s.push(i);
            get=1;
        }
        while(!s.empty()){
            res.push_back(asteroids[s.top()]);
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
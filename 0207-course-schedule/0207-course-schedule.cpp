class Solution {
public:
    //time O(n)
    //space O(n)
    bool canFinish(int numC, vector<vector<int>>& course) {
        vector<int> in(numC); //indgree 
        vector<vector<int>> out(numC); //outdegree
        
        for(auto a : course){
            int fin=a[0],need=a[1];
            in[fin]++; //increase node's incoming path 
            out[need].push_back(fin);
        }
        
        //find course that doesn't require prerequisites
        vector<int> v;
        for(int i=0;i<numC;i++){
            if(!in[i])
                v.push_back(i);
        }
        
        for(int i=0;i<v.size();i++){
            for(auto node : out[v[i]]){
                if(--in[node]==0) //become independent course
                    v.push_back(node);
            }
        }
        return v.size()==numC ? 1 : 0;
    }
};
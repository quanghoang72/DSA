class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        //add all string in bank to set
        unordered_set<string> st{bank.begin(),bank.end()};

        //if end mutaion is not in list return -1;
        if(!st.count(end)) return -1;

        //start BFS by pushing the starting mutation
        queue<string> q;
        q.push(start);
        int steps=0,s;
        string cur,t;
        while(!q.empty()){
            s=q.size();
            while(s--){
                cur=q.front();
                q.pop();

                //If we reach end mutation
                if(cur==end) return steps;

                //We erase the cur mutation in order to avoid redundant checking
                st.erase(cur);

                //try to check every possible A C G T character for everyelement
                //if the mutation is already available in the bank add to queue
                //else we cant check that genetic mutation
                for(int i=0;i<8;i++){
                    t=cur;
                    t[i]='A';
                    if(st.count(t)) q.push(t);
                    t[i]='C';
                    if(st.count(t)) q.push(t);
                    t[i]='G';
                    if(st.count(t)) q.push(t);
                    t[i]='T';
                    if(st.count(t)) q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};
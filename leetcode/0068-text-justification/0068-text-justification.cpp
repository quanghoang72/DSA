class Solution {
public:
    //time O(n^2)
    //space O(n)
    vector<string> fullJustify(vector<string>& words, int sz) {
        vector<string> res;
        int n=words.size();
        int i=0;
        while(i<n){
            int j=i+1;
            int cur_size=words[i].size();
            //find words are hold in 1 line
            for(j;j<n;j++){
                cur_size+=words[j].size();
                if( (sz-cur_size)/(j-i) <=0){
                    cur_size-=words[j].size();
                    break;
                }
            }
            //create line
            string temp=mergeString(words,i,j-1,sz,cur_size,j==n);
            res.push_back(temp);
            i=j;
        }
        return res;
    }
    string mergeString(vector<string>&words,int start,int end,int sz,int total,bool last){
        //how many gap between words
        //if gap==0 --> one word only (left-justified) --> filled with empty space
        //if this is the last line --> gap between words should be 1 and fill rest with space
        int gap=end-start; 
        int empty=sz-total; //empty space left
        string s;
        int g;
        for(int i=start;i<=end;i++){
            s+=words[i];
            //check if one word only
            //else check if this is last line 
            g=gap!=0 ? (last ? 1 : ceil(empty*1.0/gap)) : empty;
            
            string space;
            for(int j=0;j<g;j++)
                space+=" ";
            
            if(!space.empty()) s+=space;
            
            empty-=g;
            gap--;
        }
        
        return s;
    }
};
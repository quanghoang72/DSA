class Solution {
public:
    //k total unique characters
    //time O(nlogk)
    //space O(1)
    string reorganizeString(string s) {
        string res="";
        vector<int> freq(26);
        int maxfreq=1;
        
        for(char &c:s){
            int t= c-'a';
            freq[t]++;
            maxfreq=max(maxfreq,freq[t]);
        }
        
        if(maxfreq==1)
          return s;
        priority_queue< pair<int,char>, vector<pair<int,char>>> maxheap;
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                maxheap.push({freq[i],i+'a'});
        }
        char prev=' ';
        pair<int,char> temp;
        
        while(!maxheap.empty()){
            int time=maxheap.top().first;
            char most=maxheap.top().second;
            maxheap.pop();
            
            if (prev==most){
                if(maxheap.empty()) return "";
                temp={time,most};
                time=maxheap.top().first;
                most=maxheap.top().second;
                maxheap.pop();
                maxheap.push(temp);
            }
            
            if(time-1>0)
                maxheap.push({time-1,most});
            
            res+=most;
            prev=most;
        }
        return res;
    }
};
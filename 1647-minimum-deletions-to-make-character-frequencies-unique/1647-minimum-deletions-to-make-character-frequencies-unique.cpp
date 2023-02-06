class Solution {
public:
    //time O(nlogn)
    //space O(n)
    int minDeletions(string s) {
        int res=0;
        sort(s.begin(),s.end());
        int n=s.size();
        vector<int> mp(n+1);
        
        int i=0;
        int maxf=0;//store the max frequence character
        
        //calculate the frequency
        while(i<n){
            int j=i;
            while(j+1 < n && s[j]==s[j+1]) j++;
            int length=j-i+1;
            maxf=max(maxf,length);
            mp[length]++;
            i=j;
            i++;
        }
        
        //ignore 0 freq
        for(int i=maxf;i>0;i--){
            int sz=mp[i];
            int length=i;
            while(sz>1){ //there are more charcter appears in this frequency
                int next=length-1; //next less size of freq
                res+=1; //delete 1 character
                mp[next]++; //add whatever deleted character to the next frequency
                
                //decrease current freq
                mp[length]--; 
                sz--;
            }
        }
        return res;
    }
};
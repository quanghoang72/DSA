class Solution {
public:
    int minDeletions(string s) {
    //time O(nlogn)
    //space O(n)
//         int res=0;
//         sort(s.begin(),s.end());
//         int n=s.size();
//         vector<int> mp(n+1);
        
//         int i=0;
//         int maxf=0;//store the max frequence character
        
//         //calculate the frequency
//         while(i<n){
//             int j=i;
//             while(j+1 < n && s[j]==s[j+1]) j++;
//             int length=j-i+1;
//             maxf=max(maxf,length);
//             mp[length]++;
//             i=j;
//             i++;
//         }
        
//         //ignore 0 freq
//         for(int i=maxf;i>0;i--){
//             int sz=mp[i];
//             int length=i;
//             while(sz>1){ //there are more charcter appears in this frequency
//                 int next=length-1; //next less size of freq
//                 res+=1; //delete 1 character
//                 mp[next]++; //add whatever deleted character to the next frequency
                
//                 //decrease current freq
//                 mp[length]--; 
//                 sz--;
//             }
//         }
//         return res;
        
        
        //time O(n)
        //space O(1)
        vector<int> freq (26, 0);
        for (char c : s) freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        int res = 0;
        
        //ignore the most frequency(25) start from 24
        for (int i = 24; i >= 0; i--) {
            if(freq[i] == 0) break; //there is no character left      
            
            //if the current character has more freq then previous
            //current should be deleted by previous -1 times to avoid being identical freq 
            if(freq[i] >= freq[i+1]){
                int current = freq[i]; 
                freq[i] = max(0, freq[i+1] -1);
                res += current - freq[i]; //deletion times to be less than previous freq
            }
        }
        return res;
    }
};
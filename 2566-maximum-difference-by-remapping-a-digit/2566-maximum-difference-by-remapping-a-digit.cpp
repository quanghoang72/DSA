class Solution {
public:
    int minMaxDifference(int a) {
        string num=to_string(a);
        int n=num.size();
        int i=0;
        while(i<n){
            if(num[i]!='9') break;
            i++;
        }
        char largest= num[i];
        i=0;
        while(i<n){
            if(num[i]!='0') break;
            i++;
        }
        char smallest= num[i];
        string mn=num;
        for(i=0;i<n;i++){
            if(num[i]==largest) {
                num[i]='9';
            }
        }
        for(i=0;i<n;i++){
            if(mn[i]==smallest){
                mn[i]='0';
            }
        }
        return stoi(num)-stoi(mn);
        
    }
};
class Solution{
    public:
    // Function to find number of bits needed to be 
    // flipped to convert A to B
    
    int count(int x){
        int res=0;
        while(x){
            x&=(x-1);
            res++;
        }
        return res;
    }
    int countBitsFlip(int a, int b){
        int x=a^b;
        return count(x);
    }
};
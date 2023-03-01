class Solution {
public:
    vector<int> sortArray(vector<int>& a) {
        int n=a.size();
        merge(a,0,n-1);
        return a;
    }
    void merge(vector<int> &a,int start, int end){
        if(start<end){
            int mid=start+(end-start)/2;
            merge(a,start,mid);
            merge(a,mid+1,end);
            mergesort(a,start,mid,end);
        }
    }
    void mergesort(vector<int>&a,int start,int mid,int end){
        int left=mid-start+1;
        int right=end-mid;
        vector<int> ltemp(left);
        vector<int> rtemp(right);
        
        for(int i=0;i<left;i++){
            ltemp[i]=a[start+i];
        }
        for(int i=0;i<right;i++){
            rtemp[i]=a[mid+i+1];
        }
        
        int i=0,j=0,idx=start;
        while(i < left && j <right){
            if(ltemp[i] < rtemp[j]){
                a[idx++]=ltemp[i++];
            }
            else{
                a[idx++]=rtemp[j++];
            } 
        }
        while(i<left) a[idx++]=ltemp[i++];
        while(j < right) a[idx++]=rtemp[j++];
    }
};
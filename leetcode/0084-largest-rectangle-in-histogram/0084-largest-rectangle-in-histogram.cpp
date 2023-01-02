class Solution {
public:
    //time O(n)
    //space O(n)
    
    // if the next rectangle is less than top stack it means that 
    // the larger result should be on the left --> smaller element creates a boudary
    // elements in increasing order dedicates rectangle can spread in horizontal form 
    //and will end whenenver it meets the boundary
    // add 0 number to the back to avoid all elements are in increasing order (1,2,3,4)
    int largestRectangleArea(vector<int>& a) {
        a.push_back(0);
        int n=a.size();
        stack<int> s;
        int res=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()] > a[i]){
                int height=a[s.top()];  s.pop();
                int idx=s.empty() ? -1 : s.top();
                res=max(res,height*(i-idx-1));
            }
            s.push(i);
        }
        return res;
    }
};
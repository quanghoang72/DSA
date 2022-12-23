class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){ //only swap with the first element
            string temp=s;
            s+=s; //duplicate string
            
            //only need to traverse less than original length string
            //because we have duplicate the string. If we iterate more than size then
            //it will be start over again like the original string.
            for(int i=1;i<temp.size();i++){
                //to compare the first character of both string which string start with smaller element
                temp=min(temp,s.substr(i,temp.size()));
            }
            return temp;
        }
        //if k>1 then we can swap any <k element until we get the lexicographical order
        sort(begin(s),end(s));
        return s;
    }
};
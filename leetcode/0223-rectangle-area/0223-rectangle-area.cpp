class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
        int s1=(C-A)*(D-B);
        int s2=(G-E)*(H-F);
        //not overlap
        // left ||  right || up || bottom
        if(C<=E || A >= G || B>=H || D<=F)
            return s1+s2;
        //4 corner overlap:top - bot * right - left
        return s1+s2-((min(H,D)-max(B,F))*(min(C,G)-max(A,E)));
    }
};
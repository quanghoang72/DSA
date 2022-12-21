class Solution {
public:
    
    //default value will increment each
    // using opposite color 1|-1 for the dislikes
    enum COLOR_CONSTANT{
        GREEN = -1,         // -1
        NOT_COLORED,       // 0
        BLUE                // 1
    };
    
    bool helper(const int &personID,const int &color,unordered_map <int,int> &colorTable,
                unordered_map <int,vector<int>> &dislikeTable){
        
        colorTable[personID]=color;
        
        for(const int& other : dislikeTable[personID]){
            
            //dislike person cant have the same color
            if(colorTable[other]==color) return false;
            
            if(colorTable[other] == NOT_COLORED && 
               (!helper(other, -color , colorTable, dislikeTable))
              )
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        

        
        //simple test case
        if( n == 1 || dislikes.size() <=1 ){
            return true;
        }
        
        // dislike graph
        unordered_map< int, vector<int> > dislikeTable;
        
        // key: personID
        // value: color of person
        unordered_map< int, int> colorTable;
        
        
        //build dislike graph
        for( const auto &relation : dislikes ){
            
            int p1 = relation[0], p2 = relation[1];
            
            dislikeTable[p1].emplace_back( p2 );
            dislikeTable[p2].emplace_back( p1 );
            
        }
        
        // Using dfs to assign color to individual by helper bool function
        for( int personID = 1 ; personID <= n ; personID++){
            
            //NOT_COLORED is an initial default value for every person
            if( colorTable[personID] == NOT_COLORED && 
               (!helper(personID, BLUE, colorTable, dislikeTable))
              )
                    return false;
        }
        

        return true;        
    }
};
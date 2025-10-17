class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> after(2 , vector<int> (3, 0));
        vector<vector<int>> cur(2 , vector<int> (3, 0));
        
       
        for(int i=n-1 ; i>=0 ; --i){
            for(int j=0 ; j<=1 ; ++j){
                for(int k=1 ; k<=2 ; ++k){
                    if(j==1){
                        cur[j][k] = max(-prices[i]+after[0][k] , after[1][k]); 
               x     }
                    else{
                        cur[j][k] = max(prices[i] + after[1][k-1] , after[0][k]);
                    }
                }
            }after = cur;
        }


        return after[1][2];
    }
};

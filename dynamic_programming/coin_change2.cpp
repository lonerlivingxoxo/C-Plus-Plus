class Solution {
public:
    int solve(int i , vector<int>& coins , int amount , vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(i==coins.size()) return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int nottake = solve(i+1 , coins , amount, dp);
        int take = 0;
        if(coins[i]<=amount){
            take = solve(i , coins , amount-coins[i] , dp);
        }
        return dp[i][amount] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1 , vector<int>(amount+1, -1));
        return solve(0 , coins , amount , dp);
    }
};

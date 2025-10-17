class Solution {
public:
    // bool solve(int i , int target, vector<int>& nums , vector<vector<int>>& dp){
    //     if(target == 0) return true ;
    //     if(i==0) return target == nums[0];
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     int ntake = solve(i-1 , target , nums , dp);
    //     int take = false;
    //     if(target>=nums[i]){
    //         take = solve(i-1 , target-nums[i] , nums , dp);
    //     }
    //     return dp[i][target] = take || ntake;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i=0 ; i<n ; ++i){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target = sum/2;
        vector<int>prev(target+1 , 0);
        for(int i=0 ; i<n ; ++i){
            prev[0]=true;
        }
        if(nums[0]<=target)
        {prev[nums[0]]=true;}
        for(int i=1 ; i<n ; ++i){
            vector<int>curr(target+1 , 0);
            for(int j=1 ; j<=target ; ++j){
                int ntake = prev[j];
                int take = false;
                if(j>=nums[i]){
                    take = prev[j-nums[i]];
                }
                curr[j] = take||ntake;
            }
            prev = curr;
        }
        return prev[target];
    }
};

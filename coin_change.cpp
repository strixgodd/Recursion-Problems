class Solution {
    public:
    // normal recursion
    int recurse(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0)
            return INT_MAX;
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=recurse(coins,amount-coins[i]);
            if(ans!=INT_MAX)
                mini=min(mini,ans+1);
            cout<<ans<<" ";
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount){
        int ans=recurse(coins,amount);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }


    //dp->memorization (top-down approach)
     int recurseDPMem(vector<int>& coins,int amount,vector<int>& dp){
            if(amount==0){
                return 0;
            }
            if(amount<0)
                return INT_MAX;
            if(dp[amount]!=-1)
                return dp[amount];
            int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                int ans=recurseDPMem(coins,amount-coins[i],dp);
                if(ans!=INT_MAX)
                    mini=min(mini,ans+1);
            }
            dp[amount]=mini;
            return mini;
        }
        int coinChangeDP(vector<int>& coins, int amount){
            vector<int> dp(amount+1,-1);
            int ans=recurseDPMem(coins,amount,dp);
            for(int i=0;i<=amount;i++)
                cout<<dp[i]<<" ";
            if(ans==INT_MAX)
                return -1;
            return ans;
        }
        //dp tabulation -> bottom up approach, i can observe only that dp[i] depends on coins.size() previous indices so space optimization of O(1) is not possible
         int coinChangeBUP(vector<int>& coins, int amount){
            vector<int> dp(amount+1,INT_MAX);
            dp[0]=0;
            for(int i=1;i<=amount;i++){
                int mini=INT_MAX;
                for(int j=0;j<coins.size();j++){
                    if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                        dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
            if(dp[amount]==INT_MAX)
                return -1;
            return dp[amount];
        }
};

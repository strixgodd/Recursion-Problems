// normal recursion

class Solution {
public:
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
};
//dp 
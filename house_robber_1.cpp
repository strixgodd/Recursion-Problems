class Solution {
public:
    //normal recursion
    int recurse(vector<int>& nums,int index){
        if(index>=nums.size())
            return 0;
        int inc=recurse(nums,index+2)+nums[index];
        int exc=recurse(nums,index+1);
        return max(inc,exc);
    }
    int rob(vector<int>& nums) {
        return recurse(nums,0);
    }
    //recursion + DP(Memorization- top down)
    int recurseDP(vector<int>& nums,vector<int>& dp,int index){
        if(index>=nums.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];

        int inc=recurseDP(nums,dp,index+2)+nums[index];
        int exc=recurseDP(nums,dp,index+1);
        dp[index]=max(inc,exc);
        return dp[index];
    }
    int robDP(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return recurseDP(nums,dp,0);
    }
    //BUP Tabulation
    int robBUP(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=nums[n-1];
        if(n==1)
            return nums[0];
        dp[n-2]=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            int inc=dp[i+2]+nums[i];
            int exc=dp[i+1];
            dp[i]=max(inc,exc);
        }
        for(int i=0;i<dp.size();i++)
            cout<<dp[i]<<" ";
        return dp[0];
    }
    //space optimization
    int robSO(vector<int>& nums) {
        int n=nums.size();
        int prev0=nums[n-1];
        if(n==1)
            return nums[0];
        int prev1=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            int inc=prev0+nums[i];
            int exc=prev1;
            int ans=max(inc,exc);
            prev0=prev1;
            prev1=ans;
        }
        return prev1;
    }

};
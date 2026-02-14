class Solution {
public:
    // time and space optimized- space optimized version of DP BUP Tabulation method
    int solve(vector<int>& nums, int start){
        int n=nums.size(),end;
        if(start)
            end=n-1;
        else
            end=n-2;
        int prev0=nums[end];
        int prev1=max(nums[end],nums[end-1]);
        for(int i=end-2;i>=start;i--){
            int inc=nums[i]+prev0;
            int exc=prev1;
            int ans=max(inc,exc);
            prev0=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n==3)
            return max(nums[0],max(nums[1],nums[2]));
        return max(solve(nums,0),solve(nums,1));
    }
};
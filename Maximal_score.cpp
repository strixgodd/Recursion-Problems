// class Solution {
// public:
//     int solve(vector<vector<char>>& matrix,int r,int c,int &maxi){
//         if(r>=matrix.size() || c>=matrix[0].size()){
//             return 0;
//         }

//         int right=solve(matrix,r,c+1,maxi,dp);
//         int down=solve(matrix,r+1,c,maxi,dp);
//         int diagonal=solve(matrix,r+1,c+1,maxi,dp);
//         if(matrix[r][c]=='1'){
//             int ans=1+min(right,min(down,diagonal));
//             maxi=max(ans,maxi);
//             cout<<"("<<r<<","<<c<<") "<<ans<<" ";
//             return ans;
//         }
//         return 0;
        
//     }
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int maxi=0;
//         solve(matrix,0,0,maxi);
//         return maxi*maxi;
//     }
// };


//recursion+memorization top down approach
class Solution {
public:
    int solve(vector<vector<char>>& matrix,int r,int c,int &maxi,vector<vector<int>> &dp){
        if(r>=matrix.size() || c>=matrix[0].size()){
            return 0;
        }
        if(dp[r][c]!=-1)
            return dp[r][c];

        int right=solve(matrix,r,c+1,maxi,dp);
        int down=solve(matrix,r+1,c,maxi,dp);
        int diagonal=solve(matrix,r+1,c+1,maxi,dp);
        if(matrix[r][c]=='1'){
            dp[r][c]=1+min(right,min(down,diagonal));
            maxi=max(dp[r][c],maxi);
            // cout<<"("<<r<<","<<c<<") "<<ans<<" ";
            return dp[r][c];
        }
        dp[r][c]=0;
        return 0;
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        solve(matrix,0,0,maxi,dp);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return maxi*maxi;
    }
};
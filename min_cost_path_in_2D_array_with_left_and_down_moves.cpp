#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int c, int r, int col, int row){
        if(c>=col || r>=row)
            return 0;
        return 1;
    }
    int recurse(vector<vector<int>>& grid, int k, int r, int c,vector<vector<int>>& dp){
        if(r==grid.size()-1 && c==grid[0].size()-1){
            dp[r][c]=0;
            return 0;
        }
        if(dp[r][c]!=-1)
            return dp[r][c];
            return 0;
        if(r>=grid.size() || c>=grid[0].size())
            return INT_MAX;
        int cost_right,cost_down;

        if(c+1>=grid[0].size())
            cost_right=recurse(grid,k,r,c+1,dp);
        else
            cost_right=recurse(grid,k,r,c+1,dp)+grid[r][c+1];

        if(r+1>=grid.size())
            cost_down=recurse(grid,k,r+1,c,dp);
        else
            cost_down=recurse(grid,k,r+1,c,dp)+grid[r+1][c];
        dp[r][c]= min(cost_right,cost_down);
        return dp[r][c];

    }
    int minCost(vector<vector<int>>& grid, int k) {
        int col=grid[0].size();
        int row=grid.size();
        int cost=0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return recurse(grid,k,0,0,dp);
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid = {
    {1, 3, 1, 2, 9},
    {2, 1, 8, 1, 2},
    {4, 2, 1, 3, 1},
    {5, 3, 2, 1, 1}
    };

    // vector<vector<int>> grid={{1,3,3},{2,5,4},{4,3,5}};
    
    cout<<s.minCost(grid,1);
    return 0;
}
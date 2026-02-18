#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int c, int r, int col, int row){
        if(c>=col || r>=row)
            return 0;
        return 1;
    }
    int recurse(vector<vector<int>>& grid, int k, int r, int c, int row, int col,int ans,int cost){
        if(c==col-1 && r==row-1){
            ans=min(ans,cost);
            return ans; 
        }
        //pruning
        if(cost>=ans) return ans;
        //MOVE right
        if(isSafe(r,c+1,row,col)){
            cost+=grid[r][c+1];
            cout<<"("<<r<<","<<c+1<<")"<<" ";
            ans=min(ans,recurse(grid,k,r,c+1,row,col,ans,cost)); 
            cost-=grid[r][c+1];
        }
        //MOVE down
        if(isSafe(r+1,c,row,col)){
            cost+=grid[r+1][c];
            cout<<"("<<r+1<<","<<c<<")"<<" ";
            ans=min(ans,recurse(grid,k,r+1,c,row,col,ans,cost)); 
            cost-=grid[r+1][c];
        }
        
        // Teleport 
        if(k!=0){
            for(int i=r;i<row;i++){
                for(int j=c;j<col;j++){
                    if((i!=r || j!=c)&&(grid[r][c]>=grid[i][j])){
                        cout<<"("<<i<<","<<j<<")"<<" ";
                        ans=min(ans,recurse(grid,k-1,i,j,row,col,ans,cost));
                    }
                }
            }
        }
        return ans;

    }
    int minCost(vector<vector<int>>& grid, int k) {
        int col=grid[0].size();
        int row=grid.size();
        int ans=INT_MAX;
        int cost=0;
        return recurse(grid,k,0,0,row,col,ans,cost);
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
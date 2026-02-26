#include <bits/stdc++.h>
int solveRecursively(int n,int x,int y,int z){
	if(n<0)
		return INT_MIN;
	if(n==0)
		return 0;
	int l=solveRecursively(n-x,x,y,z)+1;
	int m=solveRecursively(n-y,x,y,z)+1;
	int r=solveRecursively(n-z,x,y,z)+1;
	int maxi=max(l,max(m,r));
	return maxi;

}
int solveRecursivelyMem(int n,int x,int y,int z,vector<int>& dp){
	if(n<0)
		return INT_MIN;
	if(n==0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	int l=solveRecursivelyMem(n-x,x,y,z,dp)+1;
	int m=solveRecursivelyMem(n-y,x,y,z,dp)+1;
	int r=solveRecursivelyMem(n-z,x,y,z,dp)+1;
	 dp[n]=max(l,max(m,r));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z){
	int a=solveRecursively(n,x,y,z);
	if(a<0)
		return 0;
	return a;
}
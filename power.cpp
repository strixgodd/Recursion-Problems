//https://leetcode.com/problems/powx-n/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        //edge cases
        if (n==0) return 1.0;
        //base cases
        if (n==1) 
            return x;
        if (n==-1) 
            return 1.0/x;
        
        double d = myPow(x,n/2);
        //recursive cases
        if (n%2==0)// if n is even
            return d*d;
        // if n is odd
        if (n>0)
            return x*d*d;
        else
            return d*d/x;
    }
};

int main(){
    Solution s;
    cout<<s.myPow(2,3);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
    if(n <= 1)return n;
    vector<int>dp(n,-1);
    return helper(n,dp);
}

helper(int n,vector<int>&dp){
    if(n <= 1)return n;
    if(dp[n] != -1)return dp[n];
    int ans1= staircase(n-1);
    int ans2 = staircase(n-2);
    int ans3= staircase(n-3);

    return dp[n] = ans1+ans2+ans3;
}
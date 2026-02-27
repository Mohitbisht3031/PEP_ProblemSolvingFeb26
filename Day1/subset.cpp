#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&nums,vector<vector<int>>&ans,vector<int>&v,int i){
    if(nums.size() == i){
        ans.push_back(v);
        return;
    }
    // take curr num
    v.push_back(nums[i]);
    helper(nums,ans,v,i+1);
    v.pop_back();
    // not take the curr num
    helper(nums,ans,v,i+1);
    return;
}

vector<vector<int>> subset(vector<int>&nums){
    if(nums.size() ==1 )return {nums};
    vector<vector<int>>ans;
    vector<int>v;
    helper(nums,ans,v,0);
    return ans;
}
#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&nums,vector<vecotr<int>>&ans,vector<int>&v,unordered_map<int,int>&mp){
    if(v.size() == nums.size()){
        ans.push_back(v);
        return;
    }

    // my part -> to select an element to populate my current blank space
    for(int e:nums){
        if(mp.count(e)==0){
            v.push_back(e);
            mp[e]++;
            helper(nums,ans,v); //Rec call to make the remaining elemet
            v.pop_back();
            mp.erase(e);
        }
    }
    return;4
}

vector<vector<int>> permutation(vector<int>&nums){
    if(nums.size() <= 1 )return {nums};
    vector<vector<int>>ans;
    vector<int>v;
    unordered_map<int,int>mp;
    helper(nums,ans,v,mp);

    return ans;
}
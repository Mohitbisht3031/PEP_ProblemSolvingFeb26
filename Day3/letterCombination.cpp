#include<bits/stdc++.h>
using namespace std;

void helper(string &str,int i,vector<string>&ans,string&s,vector<string>&mp){
    if(i >= str.size()){
        ans.push_back(s);
        return;
    }

    // my part
    for(int i = 0;i<mp[str[i]-'0'].size();i++){
        s.push_back(mp[str[i] - '0'][i]);
        helper(str,i+1,ans,s,mp); // rec call
        s.pop_back(); // backtracking
    }

    return ;
}

vector<string> letterCombination(string &str){
    vector<string>mp(10,"");
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";

    vector<string>ans;
    string s;
    helper(str,0,ans,s,mp);
    return ans;
}
#include<bits/stdc++.h>
using namespace std;

void helper(string &str,int i,vector<string>&ans,string &s){
    if(i >= str.size()){
        ans.push_back(s);
        return;
    }

    // my part 
    int d = (str[i] - '0');
    s.push_back(('a' + (d - 1)));
    helper(str,i+1,ans,s); // rec call
    s.pop_back(); // backtracking

    if((d == 1 || d == 2) && i+1 < str.size()){
        int nd = (str[i+1] - '0');
        if(d == 2 && nd <= 6){
            int num = (d*10) + nd;
            s.push_back(('a' + (num - 1)));
        }else if(d == 1){
            int num = (d*10) + nd;
            s.push_back(('a' + (num - 1)));
        }
        helper(str,i+2,ans,s);
        s.pop_back();
    }

    return;
}

vector<string> stringMaker(string &str){
    if(str.size() == 1){
        return {('a' + ((str[0] - '0')-1))};
    }
    vector<string>ans;
    string s;
    helper(str,0,ans,s);
    return ans;
}
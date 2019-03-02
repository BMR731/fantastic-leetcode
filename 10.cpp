//
// Created by Saijun Hu on 2019/1/20.
//
//TODO 没有思路
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//Solution1: use the recursive to handle,accpeted,O(2^n),very slow.
class Solution1 {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match = !s.empty() && (s[0]==p[0] || p[0] == '.');
        if(p.length()>=2 && p[1]=='*'){
            //if the * in the second position,we can suppose this case is zero match;
            bool A = isMatch(s,p.substr(2));
            //this case has matched the first char, match remain part recursively
            bool B = first_match && isMatch(s.substr(1),p);
            return A || B;
        }else{
            return first_match && isMatch(s.substr(1),p.substr(1));
        }
    }
};

//use dp tech to optimize, dp[i][j] means does  s[i:] and  p[j:] match?
//then we use bottom up
//attention the short-circut evaluation reduce the boundary test;
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1));
        dp[s.length()][p.length()] = true;//base case, the blank sting must match
        for(int i=s.length();i>=0;i--){//i add at most 1
            for(int j=p.length()-1;j>=0; j--){//j add at most 2
                bool first_match = i<s.length() && (s[i]==p[j] || p[j] == '.');
                if(j<p.length()-1 && p[j+1]=='*'){
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                }else{
                    dp[i][j] = first_match && dp[i+1][j+1];//here use the 短路求值，所以不会越界
                };
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution s = Solution();

    cout<<s.isMatch(string("aab"),string("c*a*b"))<<endl;
    return 0;
}
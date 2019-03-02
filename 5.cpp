//
// Created by Saijun Hu on 2019/1/18.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

//1.brute force O(n3)
/*
class Solution {
public:
    bool is_palindromic_string(int left, int right, string s) {

        for(int i=left,j=right;i<=j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        string res;
        int maxlength = -1;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                   if(is_palindromic_string(i,j,s)) {
                       if (j - i + 1 > maxlength) {
                           maxlength = j - i + 1;
                           res = s.substr(i, j - i + 1);
                       }
                   }
            }
        }
        return res;

    }
};
*/
//2.using dp table to reduce the check string , space O(n2), time O(n2)
/*class Solution {
public:
    bool is_palindromic_string(int i, int j, string s,vector<vector<bool>>& dp) {
        if(i==j || j==i+1) return dp[i][j];
        dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        //1.brute force O(n3)
        int len = s.length();
        if(len==0) return "";
        string res;

        vector<vector<bool>> dp(len,vector<bool>(len,false));
        //the base case is following:
        //init length=1 target string
        for(int i=0;i<len;i++) dp[i][i]=true;
        //init length=2 target string
        for(int i=0;i<len-1;i++){
            dp[i][i+1] = (s[i]==s[i+1]);
        }

        int maxlength = -1;
        for(int k=1;k<=len;k++){//k is string length
            for(int i=0;i<len-k+1;i++){
                if(is_palindromic_string(i,i+k-1,s,dp)) {
                    if (k > maxlength) {
                        maxlength = k;
                        res = s.substr(i, k);
                    }
                }
            }
        }
        return res;
    }
};*/

//3.TODO expand from center,time O(n2), space O(n)
class Solution {
    int lo,maxLength;
public:
    void extend_from_center(string str, int left, int right) {
        //greedy expand
        while(left>=0 && right<str.length() && str[left]==str[right] ){
            left--;
            right++;
        }

        if(right-left-1>maxLength){
            maxLength = right-left-1;
            //attention: here real length is 'right-left-1',rather than 'right-left+1';
            //cause the left,right is break from the up 'while' loop,
            // the value has been invalid

            lo = left+1;//this is also a rectify,add 1
        }
    }

    string longestPalindrome(string s) {
        int len = s.length();
        if(len<2) return s;
        for(int i=0;i<len-1;i++){
            //The odd/even length is referring to the length
            // of the potential palindrome centered at i
            extend_from_center(s,i,i);//the length is odd,from the center
            extend_from_center(s,i,i+1);//the length is even,from the center and right
        }
        return s.substr(lo,maxLength);
    }
};
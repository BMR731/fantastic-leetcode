//
// Created by Saijun Hu on 2019/1/28.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//not so small charsets, so use brute force first,
//464 ms, faster than 14.22% of C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for (int i = 0; i < haystack.length();i++) {
            for (int j = 0; j < needle.length();) {
                if(haystack[i]==needle[j]){
                    j++;i++;
                    if(j==needle.length()) return i-j;
                }else {
                    i-=j;break;
                }
            }
        }
        return -1;
    }
};
//TODO use the version of dengjunhui's kmp,4 ms, faster than 98.67% of C++
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int len_text = haystack.length(),i = 0 ;// text string index
        int len_pat = needle.length(),j=0;//pattern string index
        if(!len_pat) return 0;
        int* next = build_next(needle);
        while(j<len_pat && i<len_text){
            if(0>j || haystack[i]==needle[j]){
                i++;j++;
                if(j==needle.length()) return i-j;
            }else{
                j=next[j];
            }
        }
        return -1;
    }

    int* build_next(string str){
        int len = str.length();
        int* N = new int[len];  N[0]= -1;
        int i = 0; //'text' string pointer
        int j = -1;//pattern string pointer
        while(i<len-1){
            if(0>j || str[i] == str[j]){
                i++;j++;
                N[i] = (str[i]!=str[j])? j: N[j];
            }else{ j = N[j];}
        }
        return N;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.strStr("hello","ll")<<endl;
    return 0;
}
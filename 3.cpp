//
// Created by Saijun Hu on 2019/1/17.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//TODO
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //思路：滑动窗口
        unordered_map<char,int> hash;//int record the char's lastest position
        int left=0,res=0;
        for(int i=0;i<s.length();i++){
            if(hash.find(s[i])!=hash.end()){
                if(left<=hash[s[i]]){ left=hash[s[i]]+1;}
            }
            hash[s[i]] = i;//if not exist, add it; visted, then update char position
            res=max(res,i-left+1);
        }
        return res;
    }

};
int main(){
    Solution s = Solution();
    string str;
    cin>>str;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}
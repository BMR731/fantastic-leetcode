//
// Created by Saijun Hu on 2019/1/22.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//brute algorithm ,4ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        int max_prefix_length=0;
        for(string str: strs)
            max_prefix_length = max(max_prefix_length,int(str.length()));
        int col=0;
        for(int i=0;i<=max_prefix_length;i++) {
            col=i;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]){
                    col = i;
                    j=strs.size();
                    i=max_prefix_length;
                }
            }
        }
        return strs[0].substr(0,col);
    }
};
//en... clean the up alg code
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                if(i==strs[j].length() || strs[j][i]!=strs[0][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
int main(){
    Solution s = Solution();
    cout<<s.longestCommonPrefix()<<endl;
    return 0;
}
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
#include <list>

using namespace std;
//backtrack tutorial example,4ms,faster than 3.58%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()<1) return vector<string>();
        vector<string> map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> strs,res;
        for (int i = 0; i < digits.length(); ++i) {
            string tmp = map[int(digits[i])-'2'];//notice here,char to int use ACSCII
            strs.push_back(tmp);
        }
        backtracking(res,strs,0,"");
        return res;
    }
    void backtracking(vector<string>& res, const vector<string>& strs,
                      int row,string chosen ){
        if(row==strs.size()){
            res.push_back(chosen);
        }else{
            //choose - explore- unchoice
            for(int j=0;j<strs[row].length();j++) {
                char c = strs[row][j];
                chosen += c;//choose
                backtracking(res, strs, row + 1, chosen);//explore
                chosen.erase(chosen.length() - 1, 1);//un choose
            }
        }
    }
};
//TODO bfs idea, a little complicated for me.0 ms, faster than 100.00%
class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
            vector<string> res;//use res as queue,then extend the string
            if(digits.empty()) return res;
            vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            res.push_back("");
            while(res.front().length() != digits.length()) {//the string not enough long
                string removed = res.front();
                res.erase(res.begin());
                string map = mapping[digits[removed.length()] - '0'];
                for(int i=0;i<map.length();i++){
                    res.push_back(removed+map[i]);
                }
            }
            return res;
    }
};
int main(){
    Solution2 s = Solution2();
    vector<string> res = s.letterCombinations("23");
    return 0;
}
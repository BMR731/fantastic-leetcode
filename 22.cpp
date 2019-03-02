//
// Created by Saijun Hu on 2019/1/24.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>

using namespace std;
//the initial idea is use permute,then filter out the valid , the coding
//process is failed, you can retry it later..

//Todo the iterative idea from others
//Use two integers to count the remaining left parenthesis (n) and the right
// parenthesis (m) to be added.At each function call add a left parenthesis
// if n >0 and add a right parenthesis if m>0. Append the result and terminate
// recursive calls when both m and n are zero.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate_helper(res,"",n,0);
        return res;
    }
    void generate_helper(vector<string>& res, string str,int remain_left_pair_num, int remain_right_pair_num){
        if(remain_left_pair_num ==0 && remain_right_pair_num==0){
            res.push_back(str);
            return;
        }
        if(remain_left_pair_num>0)
            generate_helper(res,str+'(',remain_left_pair_num-1,remain_right_pair_num+1);
        if(remain_right_pair_num>0)
            generate_helper(res,str+')',remain_left_pair_num,remain_right_pair_num-1);
            //notice here remain_left_pair_num doesn't add 1;
    }
};
int main(){
    Solution s = Solution();
    vector<string> res = s.generateParenthesis(3);
    return 0;
}
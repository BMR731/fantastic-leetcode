//
// Created by Saijun Hu on 2019/1/31.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//solution 1: brute force. use the stack to check the string is valid,
//then two for loop to iterate all substring

//TODO solution 2: dynamic programming.it's need reconsider
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int res = 0;
        vector<int> dp(len,0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);//notice here, the res update is conditioned
            }
        }
        return res;
    }
};
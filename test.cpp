//
// Created by Saijun Hu on 2019/1/23.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    void test(){
        cout<<((7410+7570+7565)*0.9*0.31+5000*0.9*0.25+5000*0.9*0.26+5000*0.27)*0.55*6.74<<endl;
    }
};
int main(){
    Solution s = Solution();
    s.test();//49349.2//36829.2
    return 0;
}
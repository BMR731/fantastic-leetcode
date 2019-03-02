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
//TODO: also a straightforward and delicate solution,48ms
class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        if(s.find("IV")!=s.npos) sum-=2;
        if(s.find("IX")!=s.npos) sum-=2;
        if(s.find("XL")!=s.npos) sum-=20;
        if(s.find("XC")!=s.npos) sum-=20;
        if(s.find("CD")!=s.npos) sum-=200;
        if(s.find("CM")!=s.npos) sum-=200;

        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]){
                case 'M': sum+=1000;break;
                case 'D': sum+=500;break;
                case 'C': sum+=100;break;
                case 'L': sum+=50;break;
                case 'X': sum+=10;break;
                case 'V': sum+=5;break;
                case 'I': sum+=1;break;
                default: break;
            }
        }
        return sum;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.romanToInt("MCMXCIV")<<endl;
    return 0;
}
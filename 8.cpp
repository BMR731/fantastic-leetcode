//
// Created by Saijun Hu on 2019/1/20.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//my solution ,1059 / 1079 test cases passed.'
//case like this"   +0 123" can't pass
//class Solution {
//public:
//    int myAtoi(string str) {
//        if(str=="") return 0;
//        int boom=0
//        bool neg= false;
//        long long  res=0;
//        string valid_str;
//        for(int i=0;i<str.length();i++){
//            int n = str[i]-48;
//            if(str[i]==' ') continue;
//
//            if(n<10 && n>=0){
//                valid_str+=str[i];
//            }else if(str[i]=='+' || str[i]=='-'){
//                valid_str+=str[i];
//            }else{break;}
//        }
//        for(int i=0;i<valid_str.length();i++){
//            if(valid_str[i]=='-' ){
//                if(boom==1) return 0;
//                neg=true;
//                boom=1;
//                continue;
//
//            }else if(valid_str[i] == '+'){
//                if(boom==1) return 0;
//                neg=false;
//                boom=1;
//                continue;
//            }else {
//                res=res*10+ static_cast<int>(valid_str[i]-48);
//            }
//        }
//        if(neg){res=-res;}
//        if(res<INT_MIN) return INT_MIN;
//        if(res>INT_MAX) return INT_MAX;
//        return res;
//    }
//};

//TODO solution 2...nick solution, approach the boundary case delicately.
class Solution{};
    int myAtoi(string str) {
        int i = 0, base = 0, sign = 1;
        while (str[i] == ' ') i++;//deal the blank char
        if (str[i] == '-') { i++; sign = -1; }//deal the sign
        else if (str[i] == '+') { i++; sign = 1; }

        while (isdigit(str[i])) {//here solve the "+-42" case ,the right result is 0;
            // 提前一位考虑溢出的情况
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && (str[i] > '7'))) {
                //if the current base = 214748364, then the last digit should be
                // less than or equal to (<=) 7 to be a valid integer; otherwise,
                // return Integer.MAX_VALUE and ignore the rest of the characters.
                //INT_MAX = 2147483647
                if (sign == -1) return INT_MIN;
                return INT_MAX;
            }
            base = base * 10 + str[i] - '0';
            i++;
        }
        return sign * base;
    }
}
int main(){
    Solution s = Solution();
    string str;
    while(cin>>str)
        cout<<s.myAtoi(str)<<endl;
    return 0;
}
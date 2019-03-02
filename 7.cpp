//
// Created by Saijun Hu on 2019/1/20.
//
#include <iostream>
using namespace std;
//Attention overflow here!!1

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;//deal the overflow
    }
};
int main(){
    Solution s = Solution();
    cout<<s.reverse(1534236469)<<endl;
    return 0;
}
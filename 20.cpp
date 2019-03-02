//
// Created by Saijun Hu on 2019/1/24.
//
#include <iostream>
#include <stack>
using namespace std;
//use the stack,0 ms, faster than 100.00% of C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> oper_stack;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    oper_stack.push(s[i]);
                    break;
                case ')':
                    if(oper_stack.empty()) return false;
                    if(oper_stack.top()=='(') oper_stack.pop();
                    else return false;
                    break;
                case ']':
                    if(oper_stack.empty()) return false;
                    if(oper_stack.top()=='[') oper_stack.pop();
                    else return false;
                    break;
                case '}':
                    if(oper_stack.empty()) return false;
                    if(oper_stack.top()=='{') oper_stack.pop();
                    else return false;
                    break;
            }
        }
        return oper_stack.empty();
    }
};
int main(){
    Solution s = Solution();
    cout<<s.isValid("([}")<<endl;
    return 0;
}
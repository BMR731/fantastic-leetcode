//
// Created by Saijun Hu on 2019/1/19.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//1. the straight-forward solution, time O(n), space O(n);
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;// trival case;
        vector<vector<char>> res(numRows,vector<char>());
        int row=0;
        int turn=1;//turn=0 down turn=1 up
        for(int i=0;i<s.length();i++){
            if(row%numRows==0 || row%numRows==numRows-1){
                turn=(turn+1)%2;
            }
            res[row].push_back(s[i]);
            if(turn==0){ row++;}
            else{ row--;}
        }
        string str;
        for(vector<char> vec : res){
            for(char c:vec){
                str+=c;
            }
        }
        return str;
    }
};
int main(){
    Solution s = Solution();
    string str;
    cin>>str;
    cout<<s.convert("AB",1)<<endl;
    return 0;
}



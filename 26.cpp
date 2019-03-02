//
// Created by Saijun Hu on 2019/1/28.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//16 ms, faster than 98.73% of C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        if(!nums.size()) return 0;
        nums[j++] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i-1]!=nums[i]) {
                nums[j++]=nums[i];
            }
        }
        return  j;
    }
};
//: 32 ms, faster than 8.88% of C++ ,library call funtion sometimes so slow!
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};
int main(){
    Solution s = Solution();
    vector<int> nums = {1,2,2};
    cout<<s.removeDuplicates(nums)<<endl;
    return 0;
}
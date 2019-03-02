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
//0 ms, faster than 100.00% of C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]==val) count++;
            else nums[i-count]=nums[i];
        }
        return nums.size()-count;
    }
};
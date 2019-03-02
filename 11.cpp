//
// Created by Saijun Hu on 2019/1/21.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//TODO two pointer solution,12ms,Time complexity : O(n). Single pass.
//Space complexity : O(1). Constant space is used
//The idea is simple, if we move the greater inward, we can't get a bigger area,
//but move shorter line inward, it may be get a bigger area.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxsize=0;
        for(int left=0,right=height.size()-1;left<right;){
            maxsize=max(maxsize,(right-left)*min(height[left],height[right]));
            (height[left]<=height[right])? left++ : right--;
        }
        return maxsize;
    }
};
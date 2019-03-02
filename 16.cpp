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
//TODO Similar the 3sum,learn from it
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min_abs=INT_MAX;
        int res;
        for(int i=0;i<nums.size()-2;i++) {
            int left=i+1,right=nums.size()-1,sum;
            while(left<right) {
                sum = nums[i] + nums[left] + nums[right];
                if(abs(sum-target)<min_abs){
                    min_abs=abs(sum-target);
                    res=sum;
                }
                if (sum == target) { return target; }
                else if (sum < target) { left++;}
                else{right--;}
            }
        }
        return res;
    }
};
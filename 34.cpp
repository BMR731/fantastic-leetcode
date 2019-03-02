//
// Created by Saijun Hu on 2019/2/8.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        //key idea: [low,high)
        int low=0;
        int high = nums.size();
        int mid=0;
        //find the left edge
        while(low<high){
            mid = (low+high)>>1;
            (target<=nums[mid]) ? high=mid : low=mid+1;
        }
        if(low>-1 && low<nums.size() && nums[low]== target) res[0] = low;

        //find the right edge; very important code!
        low=0;high =nums.size();mid=0;
        while(low<high){
            mid = (low+high)>>1;
            (target<nums[mid]) ? high=mid : low=mid+1;
        }
        low--;
        if(low>-1 && low<nums.size() && nums[low]== target) res[1] = low;
        return res;
    }
};